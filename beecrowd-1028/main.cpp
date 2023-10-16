#include <iostream>

int MDC(int n1, int n2) {
    if (n1 == n2) {
        return n1;
    }
    if (n1 > n2) {
        return MDC(n1 - n2, n2);
    }
    return MDC(n1, n2 - n1);
}

int main() {
    int cases;
    std::cin >> cases;
    for (int i = 0; i < cases; i++) {
        int friend1, friend2;
        std::cin >> friend1 >> friend2;
        std::cout << MDC(friend1, friend2) << std::endl;
    }
    return 0;
}
