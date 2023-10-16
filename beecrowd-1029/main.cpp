#include <iostream>

int calls;

int fib(int n, bool rec = false) {
    if (rec) {
        calls++;
    }
    if (n == 0 || n == 1) {
        return n;
    }
    return fib(n-1, true) + fib(n-2, true);
}

int main() {
    int cases;
    std::cin >> cases;
    for (int i = 0; i < cases; i++) {
        int input;
        calls = 0;
        std::cin >> input;
        int f = fib(input);
        std::cout << "fib(" << input << ") = " << calls << " calls = " << f << std::endl;
    }
    return 0;
}
