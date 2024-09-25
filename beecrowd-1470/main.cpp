#include <iostream>
#include <vector>

// so thats a structure of a trees node where every children is one candidate fold 
struct Node {
    std::vector<int> data;
    std::vector<Node> children;
};

bool compare(std::vector<int>& v1, std::vector<int>& v2) {
    bool equal = true;
    int n1 = v1.size(), n2 = v2.size();
    if (n1 != n2) {
        return false;
    }
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            equal = false;
            break;
        }
    }
    if (equal) {
        return true;
    }
    // lets also check if one is the reverse of the other
    for (int i = 0; i < n1; i++) {
        if (v1[i] != v2[n2 - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool sumArray(std::vector<int>& v1, std::vector<int>& v2) {
    int sum1 = 0, sum2 = 0;
    int l = std::max(v1.size(), v2.size());
    for (int i = 0, j = 0; i < l; i++, j++) {
        if (i < v1.size()) {
            sum1 += v1[i];
        }
        if (j < v2.size()) {
            sum2 += v2[j];
        }
    }
    return sum1 == sum2;
}

bool generateAndTestChildren(Node n, std::vector<int>& goal) {
    // optimization: if arrays are equal or one is reverse of the other, than it can be folded
    if (compare(n.data, goal)) {
        return true;
    }
    // optimization: one can only be the fold of the other if the sum of the elements is equal
    if (!sumArray(n.data, goal)) {
        return false;
    }

    // now lets find all candidate children nodes and test them
    int startSize = n.data.size();
    // can only fold if the start vector has more than 1 element and has more elements than the goal vector
    // equal size were already checked
    if (startSize > 1 && startSize > goal.size()) {
        // lets generate all the possible folds
        for (int i = 1; i < startSize; i++) {
            int start = i - 1;
            int end = i;
            Node children;
            while(true) {
                // break condition
                if (start < 0 || end == startSize) {
                    break;
                }
                children.data.push_back(n.data[start] + n.data[end]);
                start--;
                end++;
            }
            // theres still numbers left (when the fold leaves alone values at the start or the end)
            if (start < 0 && end < startSize) {
                for (int i = end; i < startSize; i++) {
                    children.data.push_back(n.data[i]);
                }
            }
            else if (start >= 0 && end == startSize) {
                for (int i = start; i >=0; i--) {
                    children.data.push_back(n.data[i]);
                }
            }

            // lets check if this children is a candidate
            if (children.data.size() >= goal.size()) {
                n.children.push_back(children);
            }
        }

        for (int i = 0; i < n.children.size(); i++) {
            if (generateAndTestChildren(n.children[i], goal)) {
                return true;
            }
        }
    }
    return false;
} 

char canFold(Node n, std::vector<int>& goal) {
    if (generateAndTestChildren(n, goal)) {
        return 'S';
    }
    return 'N';
}

int main() {
    int n1, n2;
    int i = 1;
    while(std::cin >> n1) {
        std::vector<int> in(n1);
        for (int i = 0; i < n1; i++) {
            std::cin >> in[i];
        }
        std::cin >> n2;
        std::vector<int> out(n2);
        for (int i = 0; i < n2; i++) {
            std::cin >> out[i];
        }

        Node root;
        root.data = in;

        std::cout << canFold(root, out) << std::endl;
    }
    return 0;
}