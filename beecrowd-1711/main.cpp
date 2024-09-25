#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>

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
    void print();
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

void Graph::print() {
    std::cout << "Graph with " << numVertices << " vertices" << std::endl;
    for (int i = 0; i < numVertices; i++) {
        std::cout << "|" << i << "|";
        for (Edge& e : adjacencyList[i]) {
            std::cout << " { " << e.index << ",  " << e.weight << " };";
        }
        std::cout << std::endl;
    }
}

class DFS {
private:
    Graph& graph;
    std::vector<bool> visited;
public:
    DFS(Graph& graph);
    int findCycle(int current, int parent, int origin, int cost, std::vector<int>& cycleCost);
};

DFS::DFS(Graph& graph) : graph(graph) {
    visited.resize(graph.numVertices, false);
}

int DFS::findCycle(int current, int parent, int origin, int cost, std::vector<int>& cycleCost) {
    visited[current] = true;
    for (auto& neighbor : graph.getNeighbours(current)) {
        int index = neighbor.index;
        int weight = neighbor.weight;

        // ladies and gentlemen, we got him
        if (index == origin && index != parent) {
            return cost + weight;
        }

        if (!visited[index]) {
            int costNeighbor = this->findCycle(index, current, origin, cost + weight, cycleCost);

            if (costNeighbor != 0) {
                cycleCost[current] = costNeighbor;
                cycleCost[index] = costNeighbor;
                return costNeighbor;
            }
        }
    }
    // no cycle detected
    return 0;
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
    int s, t, q;
    while (std::cin >> s >> t) {
        Graph g = Graph(s);
        for (int i = 0; i < t; i++) {
            int a, b, c;
            std::cin >> a >> b >> c;
            g.addEdge(a - 1, b - 1, c);
        }

        std::vector<int> cycleCost(s, 0);

        // find the cycle cost for each edge using DFS
        for (int i = 0; i < s; i++) {
            // optimize it, baby
            if (cycleCost[i] == 0 && g.getNeighbours(i).size() > 1) {
                DFS dfs = DFS(g);
                cycleCost[i] = dfs.findCycle(i, i, i, 0, cycleCost);
            }   
        }

        std::cin >> q;
        while (q--) {
            int x, m;
            std::cin >> x >> m;
            // find the smallest path to every node using dijkstra
            Dijkstra d = Dijkstra(g);
            d.computeShortestPaths(x - 1);
            int ans = INT_MAX;

            // for each node that have a cycle
            for (int i = 0; i < s; i++) {
                // if the cycle is greater than the length of the worm, the worm can go through
                if (cycleCost[i] >= m) {
                    // so the total lenght will be the length to traverse the cycle
                    // plus the cost of getting in and out the cycle (2 times the distance to the node that starts the cycle) 
                    ans = std::min(ans, cycleCost[i] + d.distances[i] * 2);
                }
            }

            if (ans == INT_MAX) {
                std::cout << -1 << std::endl;
            }
            else {
                std::cout << ans << std::endl;
            }
        }
    }
    
    return 0;
}
