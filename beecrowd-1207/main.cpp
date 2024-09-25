#include <iostream>
#include <vector>
#include <queue>

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

int main() {
    int n, m;
    while(std::cin >> n >> m) {
        int ans = 0;
        int graphSize = n + m + 2;
        Graph graph(graphSize);
        std::vector<int> typesOfVodka(n);
        std::vector<int> categories(m);
        std::vector<int> benefits(m);
        for (int i = 0; i < n; i++) {
            std::cin >> typesOfVodka[i];
            graph.addEdge(0, i, typesOfVodka[i]);
        }
        for (int i = 0; i < m; i++) {
            std::cin >> categories[i];
        }
        for (int i = 0; i < m; i++) {
            std::cin >> benefits[i];
            ans += benefits[i];
            graph.addEdge(n + i, graphSize, benefits[i]);
            for (int j = 0; j < categories[i]; j++) {
                int curr;
                std::cin >> curr;
                graph.addEdge(curr, n + i, 1000000);
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}