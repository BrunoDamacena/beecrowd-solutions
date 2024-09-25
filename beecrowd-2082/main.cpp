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
    void resetFlow();
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
    adjacencyList[to].emplace_back(from, weight);
}

void Graph::resetFlow() {
    for (int i = 0; i < numVertices; ++i) {
        for (Edge &e : adjacencyList[i]) {
            e.flow = 0;
        }
    }
}

void Graph::print() {
    std::cout << "Graph with " << numVertices << " vertices" << std::endl;
    for (int i = 0; i < numVertices; i++) {
        std::cout << "|" << i + 1 << "|";
        for (Edge& e : adjacencyList[i]) {
            std::cout << " { " << e.index + 1 << ",  " << e.weight << ", " << e.flow << " };";
        }
        std::cout << std::endl;
    }
}

class BFS {
private:
    Graph& graph;
    std::vector<bool> visited;
public:
    BFS(Graph& graph);
    bool search(int startVertex, int endVertex);
    std::vector<int> parent;
};

BFS::BFS(Graph& graph) : graph(graph) {
    visited.resize(graph.numVertices, false);
    parent.resize(graph.numVertices, -1);
}

bool BFS::search(int startVertex, int endVertex) {
    graph.print();
    visited.assign(graph.numVertices, false);
    visited[startVertex] = true;
    std::queue<int> breadthQueue;
    breadthQueue.push(startVertex);
    while (!breadthQueue.empty()) {
        int vertex = breadthQueue.front();
        breadthQueue.pop();
        for (auto& neighbor : graph.getNeighbours(vertex)) {
            if (!visited[neighbor.index] && neighbor.weight > neighbor.flow) {
                visited[neighbor.index] = true;
                breadthQueue.push(neighbor.index);
                parent[neighbor.index] = vertex;
            }
        }
    }
    std::cout << "Parents: ";
    for (int i = 0; i < graph.numVertices; i++) {
        std::cout << parent[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Were these vertices visited? ";
    for (int i = 0; i < graph.numVertices; i++) {
        std::cout << visited[i] << " ";
    }
    std::cout << std::endl;
    return visited[endVertex];
}

int solve(int n, Graph& g) {
    int maxFlow = 0;
    BFS bfs(g);
    while (bfs.search(0, n - 1)) {
        int residualCost = INT_MAX;
        for (int i = 0; i != n; i = bfs.parent[i]) {
            int currIdx = g.getNeighbours(i)[0].index;
            residualCost = std::min(residualCost, g.getNeighbours(currIdx)[0].weight - g.getNeighbours(currIdx)[0].flow);
        }
        maxFlow += residualCost;
        for (int i = 0; i != n; i = bfs.parent[i]) {
            int currIdx = g.getNeighbours(i)[0].index;
            g.getNeighbours(i)[0].flow += residualCost;
            g.getNeighbours(currIdx)[0].flow = std::max(0, g.getNeighbours(currIdx)[0].flow - residualCost);
        }
        // std::cout << "Current flow: " << maxFlow << std::endl;
    }
    return maxFlow;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        Graph g(n);
        for (int i = 0; i < m; i++) {
            int origin, destination, weight;
            std::cin >> origin >> destination >> weight;
            g.addEdge(origin - 1, destination - 1, weight);
        }
        // g.print();
        int ans = INT_MAX;
        for (int i = 1; i < n; i++) {
            Graph copy(n);
            for (int i = 0; i < n; i++) {
                for (const Edge& e : g.getNeighbours(i)) {
                    copy.addEdge(i, e.index, e.weight);
                }
            }
            ans = std::min(ans, solve(i, copy));
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
