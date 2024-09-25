#include <iostream>
#include <vector>
#include <climits>

#define MAX 1e9

bool possible(int n, int c, int t, std::vector<int>& bags, long long m) {
    int eater = 1;
    // how many popcorn can he eat
    // this have to be a long long because of multiplication of big numbers leading to overflow
    long long eaterCanEat = t * m;
    for (int i = 0; i < n; i++) {
        if (eaterCanEat >= bags[i]) {
            eaterCanEat -= bags[i];
        }
        else {
            eater++;
            eaterCanEat = t * m;
            i--;
        }
        // no more eaters left, not possible
        if (eater > c) {
            return false;
        }
    }
    // no more popcorn left, possible
    return true;
}

int binarySearch(int n, int c, int t, std::vector<int>& bags, int l, int r) {
    while (l < r) {
        long long m = (l+r)/2;
        if (!possible(n, c, t, bags, m)) {
            l = m + 1; 
        }
        else {
            r = m;
        }
    }
    return l;
}

int main() {
    int n, c, t;
    std::cin >> n >> c >> t;
    std::vector<int> bags(n);
    int l = 0, r = MAX;
    for (int i = 0; i < n; i++) {
        std::cin >> bags[i];
    }
    std::cout << binarySearch(n, c, t, bags, l, r) << std::endl;
    return 0;
}