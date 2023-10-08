#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n % 2 == 0) {
        n++;
    }
    for (int i = 0; i < 6; i++) {
        std::cout << n + 2*i << std::endl;
    }
    return 0;
}
