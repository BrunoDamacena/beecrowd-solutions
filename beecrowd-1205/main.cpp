#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <iomanip>

class Graph {
private:
    std::vector<std::vector<int>> adjacencyList;
    std::vector<int> vertexWeights; // Now the weights are on the vertex, not on the edge
public:
    Graph(int numVertices);
    int numVertices;
    std::vector<int> getNeighbours(int vertex);
    void addEdge(int from, int to);
    void addWeightToVertex(int vertex); // Because of how the problems input works
    int getVertexWeight(int vertex);
};

Graph::Graph(int numVertices) : numVertices(numVertices) {
    adjacencyList.resize(numVertices);
    vertexWeights.resize(numVertices, 0);
}

std::vector<int> Graph::getNeighbours(int vertex) {
    return adjacencyList[vertex];
}

void Graph::addEdge(int from, int to) {
    adjacencyList[from].push_back(to);
    adjacencyList[to].push_back(from);
}

void Graph::addWeightToVertex(int vertex) {
    vertexWeights[vertex]++;
}

int Graph::getVertexWeight(int vertex) {
    return vertexWeights[vertex];
}

class Dijkstra {
private:
    Graph& graph;
    void initializeDistances(int startIndex);
public:
    Dijkstra(Graph& graph);
    int computeShortestPaths(int startIndex, int endIndex);
    std::vector<int> distances;
};

Dijkstra::Dijkstra(Graph& graph) : graph(graph) {
    distances.resize(graph.numVertices);
}

void Dijkstra::initializeDistances(int startIndex) {
    for (int i = 0; i < graph.numVertices; i++) {
        distances[i] = INT_MAX;
    }
    distances[startIndex] = graph.getVertexWeight(startIndex);
}

int Dijkstra::computeShortestPaths(int startIndex, int endIndex) {
    // Initialization: priority queue and all distances
    std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
    initializeDistances(startIndex);
    queue.push(startIndex);

    while (!queue.empty()) {
        // Get the nearest vertex from the priority queue
        int bestNeighbor = queue.top();
        int bestDistance = distances[bestNeighbor];
        queue.pop();

        for (int neighbor : graph.getNeighbours(bestNeighbor)) {
            // Update the distance if a shorter path is found
            int newDistance = bestDistance + graph.getVertexWeight(neighbor);
            if (distances[neighbor] > newDistance) {
                distances[neighbor] = newDistance;
                queue.push(neighbor);
            }
        }
    }
    return distances[endIndex];
}

int main() {
    int N, M, K;
    double P;

    while (std::cin >> N >> M >> K >> P) {
        Graph g = Graph(N);
        for (int i = 0; i < M; i++) {
            int f, t;
            std::cin >> f >> t;
            g.addEdge(f - 1, t - 1);
        }
        int A;
        std::cin >> A;
        while(A--) {
            int s;
            std::cin >> s;
            g.addWeightToVertex(s - 1);
        }
        Dijkstra d = Dijkstra(g);
        int S, E;
        std::cin >> S >> E;
        int numberOfSoldiers = d.computeShortestPaths(S - 1, E - 1);
        double ans = std::pow(P, numberOfSoldiers);
        std::cout << std::fixed;
        std::cout << std::setprecision(3);
        std::cout << ans << std::endl;
    }

    return 0;
}