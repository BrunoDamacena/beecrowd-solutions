#include <iostream>
#include <vector>

int enigma(std::string cypher, std::string crib) {
    int ans = 0;
    for (int i = 0; i <= cypher.size() - crib.size(); i++) {
        bool possible = true;
        for (int j = 0, k = i; j < crib.size(); j++, k++) {
            if (cypher[k] == crib[j]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            ans++;
        }
    }
    return ans;
}

int main() {
    std::string cypher, crib;
    std::cin >> cypher >> crib;

    std::cout << enigma(cypher, crib) << std::endl;
    return 0;
}