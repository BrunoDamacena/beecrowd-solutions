#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

struct Edge {
    int index;
    int weight;
    int flow;

    Edge() : index(-1), weight(0), flow(0) {}
    Edge(int i, int w) : index(i), weight(w), flow(0) {}
};

class Graph {
private:
    std::vector<std::vector<Edge>> adjacencyList;
public:
    Graph(int numVertices);
    int numVertices;
    std::vector<Edge>& getNeighbours(int vertex);
    void addEdge(int from, int to, int weight);
    void print();
};

Graph::Graph(int numVertices) : numVertices(numVertices) {
    adjacencyList.resize(numVertices);
}

std::vector<Edge>& Graph::getNeighbours(int vertex) {
    return adjacencyList[vertex];
}

void Graph::addEdge(int from, int to, int weight) {
    adjacencyList[from].emplace_back(to, weight);
    // Add reverse edge with 0 capacity for residual graph
    adjacencyList[to].emplace_back(from, 0);
}

void Graph::print() {
    std::cout << "Graph with " << numVertices << " vertices" << std::endl;
    for (int i = 0; i < numVertices; i++) {
        std::cout << "|" << i + 1 << "|";
        for (Edge& e : adjacencyList[i]) {
            std::cout << " { " << e.index + 1 << ",  " << e.weight << " };";
        }
        std::cout << std::endl;
    }
}

class BFS {
private:
    Graph& graph;
    std::vector<bool> visited;
    std::queue<int> breadthQueue;
public:
    BFS(Graph& graph);
    std::vector<int> search(int startVertex, int endVertex);
};

BFS::BFS(Graph& graph) : graph(graph) {
    visited.resize(graph.numVertices, false);
}

std::vector<int> BFS::search(int startVertex, int endVertex) {
    visited[startVertex] = true;
    breadthQueue.push(startVertex);
    std::vector<int> parent(graph.numVertices, -1); // Store the parent of each vertex
    while (!breadthQueue.empty()) {
        int vertex = breadthQueue.front();
        breadthQueue.pop();
        for (auto& neighbor : graph.getNeighbours(vertex)) {
            if (!visited[neighbor.index] && neighbor.weight > neighbor.flow) {
                visited[neighbor.index] = true;
                parent[neighbor.index] = vertex; // Set the parent of the neighbor
                breadthQueue.push(neighbor.index);
            }
        }
    }
    // Backtrack from endVertex to startVertex
    std::vector<int> path;
    int currentVertex = endVertex;
    while (currentVertex != -1) {
        path.push_back(currentVertex);
        currentVertex = parent[currentVertex];
    }
    // Reverse the path to get the correct order
    std::reverse(path.begin(), path.end());
    return path;
}

void printPath(const std::vector<int>& path) {
    std::cout << "Path: ";
    for (int vertex : path) {
        std::cout << vertex + 1 << " ";
    }
    std::cout << std::endl;
}

void debug(int n, std::vector<std::vector<int>>& matches, std::vector<int>& points) {
    std::cout << "Matches remaining: " << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << matches[i][j] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << "Points: ";
        for (int i = 0; i < n; i++) {
            std::cout << "[" << i << ", " << points[i] << "] ";
        }
        std::cout << std::endl;
}

bool impossibleAtCurrentState(int n, std::vector<int>& curMatches, std::vector<int>& points) {
    int max = points[0];
    for (int i = 1; i < n; i++) {
        max += 2 * curMatches[i];
    }
    for (int i = 1; i < n; i++) {
        if (points[i] > max) {
            return true;
        }
    }
    return false;
}

int maxFlow(int n, Graph& graph) {
    int flow = 0;
    std::vector<int> parent(n + 1);
    while (true) {
        BFS bfs(graph);
        std::vector<int> path = bfs.search(0, n);
        if (path.empty()) {
            break;
        }
        int minCapacity = INT_MAX;
        for (int i = 0; i < path.size() - 1; i++) {
            std::vector<Edge>& neighbors = graph.getNeighbours(path[i]);
            for (Edge& edge : neighbors) {
                if (edge.index == path[i + 1]) {
                    minCapacity = std::min(minCapacity, edge.weight - edge.flow);
                    break;
                }
            }
        }
        for (int i = 0; i < path.size() - 1; i++) {
            std::vector<Edge>& neighbors = graph.getNeighbours(path[i]);
            for (Edge& edge : neighbors) {
                if (edge.index == path[i + 1]) {
                    edge.flow += minCapacity;
                    break;
                }
            }
            std::vector<Edge>& reverseNeighbors = graph.getNeighbours(path[i + 1]);
            for (Edge& reverseEdge : reverseNeighbors) {
                if (reverseEdge.index == path[i]) {
                    reverseEdge.flow -= minCapacity;
                    break;
                }
            }
        }
        flow += minCapacity;
    }
    return flow;
}

int main() {
    int n, m, g;
    std::cin >> n >> m >> g;
    while (n && m && g) {
        int a, b;
        char r;
        std::vector<std::vector<int>> matches(n, std::vector<int>(n, m));
        std::vector<int> points(n, 0);
        for (int i = 0; i < g; i++) {
            std::cin >> a >> r >> b;
            if (r == '=') {
                points[a]++;
                points[b]++;
            }
            else {
                points[b] += 2;
            }
            matches[a][b]--;
            matches[b][a]--;


        }

        // debug(n, matches, points);

        if (impossibleAtCurrentState(n, matches[0], points)) {
            std::cout << "N" << std::endl;
            std::cin >> n >> m >> g;
            continue;
        }

        int ans = 0;
        Graph graph(n + 1);

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += 2 * (m - matches[i][j]);
                graph.addEdge(i, j, INT_MAX);
                graph.addEdge(j, i, INT_MAX);
                graph.addEdge(n, i, 2 * (m - matches[i][j]));
                graph.addEdge(n, j, 2 * (m - matches[i][j]));
            }
        }

        if (ans == maxFlow(n, graph)) {
            std::cout << "Y" << std::endl;
        }
        else {
            std::cout << "N" << std::endl;
        }

        std::cin >> n >> m >> g;
    }
    return 0;
}