#include <iostream>

int main() {
    long long int n;
    std::cin >> n;
    for (long long int i = 2; i <= n; i += 2) {
        std::cout << i << "^2 = " << i * i << std::endl;
    }
    return 0;
}
