#include <iostream>

int main() {
    int n1, n2;
    std::cin >> n1 >> n2;

    // I want n1 to be smaller than n2
    if (n1 > n2) {
        int aux = n1;
        n1 = n2;
        n2 = aux;
    }

    // I want to start with the next odd number
    if (n1 % 2 == 0) {
        n1++;
    }
    else {
        n1 += 2;
    }

    int result = 0;

    while (n1 < n2) {
        result += n1;
        n1 += 2;
    }

    std::cout << result << std::endl;
    return 0;
}
