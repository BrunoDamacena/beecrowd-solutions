#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

typedef unsigned long long int ll;

bool isDespojado(ll n) {
    bool isPrime = true;
    for (ll i = 2; i <= std::sqrt(n); i++) {
        if (n % (i * i) == 0) {
            return false;
        }
        if (n % i == 0) {
            isPrime = false;
        }
    }
    return !isPrime;
}

int main() {
    ll n;
    std::cin >> n;
    int d = 0;
    for (ll i = 1; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            if (isDespojado(i)) {
                d++;
            }
            // avoid increasing twice for the same number
            if (i != n/i && isDespojado(n / i)) {
                d++;
            }
        }
    }
    std::cout << d << std::endl;
    return 0;
}