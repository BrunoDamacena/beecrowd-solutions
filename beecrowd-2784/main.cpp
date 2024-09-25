#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

struct Edge {
    int index;
    int weight;

    Edge() : index(-1), weight(0) {}
    Edge(int i, int w) : index(i), weight(w) {}

    // Overload the greater than operator for comparing weight
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

class Graph {
private:
    std::vector<std::vector<Edge>> adjacencyList;
public:
    Graph(int numVertices);
    int numVertices;
    std::vector<Edge> getNeighbours(int vertex);
    void addEdge(int from, int to, int weight);
};

Graph::Graph(int numVertices) : numVertices(numVertices) {
    adjacencyList.resize(numVertices);
}

std::vector<Edge> Graph::getNeighbours(int vertex) {
    return adjacencyList[vertex];
}

void Graph::addEdge(int from, int to, int weight) {
    adjacencyList[from].emplace_back(to, weight);
    adjacencyList[to].emplace_back(from, weight);
}

class Dijkstra {
private:
    Graph& graph;
    void initializeDistances(int startIndex);
public:
    Dijkstra(Graph& graph);
    void computeShortestPaths(int startIndex);
    std::vector<int> distances;
};

Dijkstra::Dijkstra(Graph& graph) : graph(graph) {
    distances.resize(graph.numVertices);
}

void Dijkstra::initializeDistances(int startIndex) {
    for (int i = 0; i < graph.numVertices; i++) {
        distances[i] = INT_MAX;
    }
    distances[startIndex] = 0;
}

void Dijkstra::computeShortestPaths(int startIndex) {
    // Initialization: priority queue and all distances
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> queue;
    initializeDistances(startIndex);
    queue.push(Edge(startIndex, 0));

    while (!queue.empty()) {
        // Get the nearest vertex from the priority queue
        int bestNeighbor = queue.top().index;
        queue.pop();

        for (Edge& neighbor : graph.getNeighbours(bestNeighbor)) {
            // Update the distance if a shorter path is found
            if (distances[bestNeighbor] != INT_MAX && distances[bestNeighbor] + neighbor.weight < distances[neighbor.index]) {
                distances[neighbor.index] = distances[bestNeighbor] + neighbor.weight;
                queue.push(Edge(neighbor.index, distances[neighbor.index]));
            }
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    Graph g = Graph(n);
    for (int i = 0; i < m; i++) {
        int from, to, ping;
        std::cin >> from >> to >> ping;
        g.addEdge(from - 1, to - 1, ping);
    }

    int s;
    std::cin >> s;
    Dijkstra d = Dijkstra(g);
    d.computeShortestPaths(s - 1);
    std::sort(d.distances.begin(), d.distances.end());
    std::cout << d.distances[d.distances.size() - 1] - d.distances[1] << std::endl;

    return 0;
}