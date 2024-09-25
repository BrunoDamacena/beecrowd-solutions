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
    // Add reverse edge with 0 capacity for residual graph
    adjacencyList[to].emplace_back(from, 0);
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

int solve(int n, int m, int a, Graph& g) {
    std::vector<int> athletesAtAirport(n, 0);
    athletesAtAirport[0] = a; // All athletes start at the first airport
    int days = 1;
    bool allArrived = false;
    while (!allArrived) {
        g.resetFlow();
        
        for (int i = 0; i < n - 1; ) {
            // std::cout << "Airport " << i + 1 << " has " << athletesAtAirport[i] << " athletes" << std::endl;
            int athletes = athletesAtAirport[i];
            if (athletes != 0) { // olny move athletes that haven't arrived yet
                BFS bfs(g);
                std::vector<int> path = bfs.search(i, n - 1);
                
                if (path.size() < 2) {
                    i++; // Move to the next airport
                    continue; // No path found for this athlete today
                }

                // printPath(path);

                // Find the minimum residual capacity in the path
                int minCapacity = INT_MAX;
                for (int j = 0; j < path.size() - 1; j++) {
                    for (Edge& e : g.getNeighbours(path[j])) {
                        if (e.index == path[j + 1]) {
                            minCapacity = std::min(minCapacity, e.weight - e.flow);
                            break;
                        }
                    }
                }

                minCapacity = std::min(minCapacity, athletes); // Can't move more athletes than there are at the airport
                int nextPos = path[1];

                // std::cout << "Can move " << minCapacity << " athletes from " << i + 1 << " to " << nextPos + 1 << std::endl;
                
                for (Edge& e : g.getNeighbours(i)) {
                    if (e.index == nextPos) {
                        e.flow += minCapacity;
                        // Update the residual capacity of the reverse edge
                        for (Edge& reverseEdge : g.getNeighbours(e.index)) {
                            if (reverseEdge.index == i) {
                                reverseEdge.flow -= minCapacity;
                                break;
                            }
                        }
                        break;
                    }
                }

                // std::cout << "Moved " << minCapacity << " athletes from " << i + 1 << " to " << nextPos + 1 << std::endl;
                athletesAtAirport[i] -= minCapacity;
                athletesAtAirport[nextPos] += minCapacity;
                
                if (athletesAtAirport[i] == 0) { // only move to the next airport if all athletes have been moved
                    i++;
                }
            }
        }
        days++;
        allArrived = athletesAtAirport[n - 1] == a;
    }

    return days;
}

int main() {
    int n, m, a;
    std::cin >> n >> m >> a;

    while (n != 0 || m != 0 || a != 0) {
        Graph g(n);
        for (int i = 0; i < m; i++) {
            int o, d, s;
            std::cin >> o >> d >> s;
            g.addEdge(o - 1, d - 1, s);
        }

        // g.print();

        std::cout << solve(n, m, a, g) << std::endl;

        std::cin >> n >> m >> a;
    }

    return 0;
}
