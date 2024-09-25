#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int charToInt(char c) {
    return c - 'a';
}

char intToChar(int n) {
    return 'a' + n;
}

class Graph {
    private:
        int n;
        std::vector<std::vector<char>> al;
    public:
        Graph(int n);
        std::vector<char> getNeighbours(int v);
        void addEdge(char from, char to);
        void print();
};

Graph::Graph(int n) : n(n) {
    al.resize(n);
}

std::vector<char> Graph::getNeighbours(int v) {
    return al[v];
}

void Graph::addEdge(char from, char to) {
    int f = charToInt(from);
    int t = charToInt(to);
    al[f].push_back(t);
    al[t].push_back(f);
}

void Graph::print() {
    std::cout << n << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "|" << i << "|";
        for (char neigh : al[i]) {
            std::cout << " " << charToInt(neigh) << " ";
        }
        std::cout << std::endl;
    }
}

void addWithNeighbours(Graph& g, std::vector<bool>& visited, std::map<int, std::vector<char>>& cMap, int i, int c) {
    if (!visited[i]) {
        visited[i] = true;
        cMap[c].push_back(intToChar(i));
        for (int n : g.getNeighbours(i)) {
            addWithNeighbours(g, visited, cMap, n, c);
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cout << "Case #" << i << ":" << std::endl;

        int v, e;
        std::cin >> v >> e;

        Graph g = Graph(v);
        for (int j = 0; j < e; j++) {
            char a, b;
            std::cin >> a >> b;
            g.addEdge(a, b);
        }

        // g.print();

        std::vector<bool> visited(v, false);
        std::map<int, std::vector<char>> cMap;
        int c = 1;

        for(int j = 0; j < v; j++) {
            addWithNeighbours(g, visited, cMap, j, c);
            c++;
        }

        int n = 0;
        for (int j = 1; j < c; j++) {
            if (cMap.find(j) != cMap.end()) {
                std::vector<char>& vInC = cMap[j];
                std::sort(vInC.begin(), vInC.end());
                for (char c : vInC) {
                    std::cout << c << ",";
                }
                std::cout << std::endl;
                n++;
            }
        }

        std::cout << n << " connected components" << std::endl << std::endl;
    }
    return 0;
}