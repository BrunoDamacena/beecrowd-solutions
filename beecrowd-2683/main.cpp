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

    // Overload the operators for comparing weight
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
    bool operator<(const Edge& other) const {
        return weight < other.weight;
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

class Prim {
private:
    Graph& graph;
public:
    Prim(Graph& graph);
    std::vector<Edge> minST;
    std::vector<Edge> maxST;
    std::vector<bool> inMinST;
    std::vector<bool> inMaxST;
    void calculateMinST();
    void calculateMaxST();
};

Prim::Prim(Graph& graph) : graph(graph) {
    minST.resize(graph.numVertices);
    maxST.resize(graph.numVertices);
    inMinST.resize(graph.numVertices, false);
    inMaxST.resize(graph.numVertices, false);
    for (int i = 0; i  < graph.numVertices; i++) {
        minST[i] = Edge(-1, INT_MAX);
        maxST[i] = Edge(-1, INT_MIN);
    }
}

void Prim::calculateMinST() {
    int startIndex = 0;
    int numVertices = graph.numVertices;
    
    // priority queue to choose the minimum weight vertex
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> queue;
    Edge start = Edge(startIndex, 0);
    minST[startIndex] = start;
    queue.push(start);

    while (!queue.empty()) {
        int bestIndex = queue.top().index;
        queue.pop();

        if (inMinST[bestIndex]) {
            continue;
        }
        
        inMinST[bestIndex] = true;

        for (Edge& neighbor : graph.getNeighbours(bestIndex)) {
            int index = neighbor.index;
            int weight = neighbor.weight;
            if (!inMinST[index] && weight < minST[index].weight) {
                Edge v = Edge(index, weight);
                minST[index] = v;
                queue.push(v);
            }
        }
    }
}

void Prim::calculateMaxST() {
    int startIndex = 0;
    int numVertices = graph.numVertices;
    
    // priority queue to choose the minimum weight vertex
    std::priority_queue<Edge, std::vector<Edge>, std::less<Edge>> queue;
    Edge start = Edge(startIndex, 0);
    maxST[startIndex] = start;
    queue.push(start);

    while (!queue.empty()) {
        int bestIndex = queue.top().index;
        queue.pop();

        if (inMaxST[bestIndex]) {
            continue;
        }
        
        inMaxST[bestIndex] = true;

        for (Edge& neighbor : graph.getNeighbours(bestIndex)) {
            int index = neighbor.index;
            int weight = neighbor.weight;
            if (!inMaxST[index] && weight > maxST[index].weight) {
                Edge v = Edge(index, weight);
                maxST[index] = v;
                queue.push(v);
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    Graph g = Graph(n);
    for (int i = 0; i < n; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        g.addEdge(u - 1, v - 1, w);
    }

    Prim p = Prim(g);
    p.calculateMinST();
    p.calculateMaxST();
    int max = 0, min = 0;
    for (int i = 0; i < n; i++) {
        if (p.inMaxST[i]) {
            max += p.maxST[i].weight;
        }
        if (p.inMinST[i]) {
            min += p.minST[i].weight;
        }
    }
    std::cout << max << std::endl << min << std::endl;

    return 0;
}