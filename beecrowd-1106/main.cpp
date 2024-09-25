#include <iostream>
#include <map>
#include <iomanip>
#include <vector>

// lets model it with a binary tree of probabilities
struct Node {
    Node() : n1(nullptr), n2(nullptr), p(nullptr) {}
    Node* n1;
    Node* n2;
    Node* p;
    std::map<int, double> prob;
};

void calc(Node* n, const std::vector<std::vector<double>>& prob) {
    if (n->n1 && n->n2) {
        calc(n->n1, prob);
        calc(n->n2, prob);
        
        std::map<int, double> newProb;
        
        for (auto it1 = n->n1->prob.begin(); it1 != n->n1->prob.end(); it1++) {
            int key1 = it1->first;
            double value1 = it1->second;
            double currProb = 0.0;
            for (auto it2 = n->n2->prob.begin(); it2 != n->n2->prob.end(); ++it2) {
                int key2 = it2->first;
                double value2 = it2->second;
                currProb += prob[key1][key2] * value2;
            }
            newProb[key1] = currProb * value1;
        }
        
        for (auto it2 = n->n2->prob.begin(); it2 != n->n2->prob.end(); ++it2) {
            int key2 = it2->first;
            double value2 = it2->second;
            double currProb = 0.0;
            for (auto it1 = n->n1->prob.begin(); it1 != n->n1->prob.end(); ++it1) {
                int key1 = it1->first;
                double value1 = it1->second;
                currProb += prob[key2][key1] * value1;
            }
            if (newProb.find(key2) != newProb.end()) {
                newProb[key2] += currProb * value2;
            } else {
                newProb[key2] = currProb * value2;
            }
        }
        n->prob = newProb;
    }
}

float getRubensProb(int n, std::vector<Node>& dragsters, const std::vector<std::vector<double>>& prob) {
    for (int i = 1; i < 2 * n; i++) {
        if (dragsters[i].p == nullptr) {
            calc(&dragsters[i], prob);
            return dragsters[i].prob[1];
        }
    }
    return 0;
}

int main() {
    int n, a, b;
    std::cin >> n;
    while (n != 0) {        
        std::vector<Node> dragsters(2 * n);
        std::vector<std::vector<double>> prob(n + 1, std::vector<double>(n + 1));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                std::cin >> prob[i][j];
            }
            dragsters[i].prob[i] = 1.0;
        }
        
        for (int i = n + 1; i < 2 * n; i++) { 
            std::cin >> a >> b;
            dragsters[a].p = &dragsters[i];
            dragsters[b].p = &dragsters[i];
            dragsters[i].n1 = &dragsters[a];
            dragsters[i].n2 = &dragsters[b];
        }
        
        std::cout << std::fixed << std::setprecision(6) << getRubensProb(n, dragsters, prob) << std::endl;
        std::cin >> n;
    }
    return 0;
}
