#include <iostream>
#include <vector>
#include <cmath>

bool canBalanceGifts(int n, std::vector<int>& gifts) {
    int a = 0;
    int b = 0;

    for (int i = 0; i < n; i++) {
        // Try to assign the gift to side a
        if (std::abs(a + gifts[i] - b) <= 5) {
            a += gifts[i];
        }
        // Try to assign the gift to side b
        else if (std::abs(b + gifts[i] - a) <= 5) {
            b += gifts[i];
        }
        // If neither side can accommodate the gift, return false
        else {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> gifts(n);
        for (int i = 0; i < n; i++) {
            std::cin >> gifts[i];
        }
        if (canBalanceGifts(n, gifts)) {
        std::cout << "Feliz Natal!" << std::endl;
        }
        else {
            std::cout << "Ho Ho Ho!" << std::endl;
        }
    }
    return 0;
}