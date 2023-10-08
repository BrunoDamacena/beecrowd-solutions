#include <iostream>

int main() {
    int cases;
    std::cin >> cases;
    int in = 0, out = 0;
    for (int i = 0; i < cases; i++) {
        int n;
        std::cin >> n;
        if (n >= 10 && n <= 20) {
            in++;
        }
        else {
            out++;
        }
    }
    std::cout << in << " in" << std::endl;
    std::cout << out << " out" << std::endl;
    return 0;
}
