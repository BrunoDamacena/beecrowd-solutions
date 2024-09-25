#include <iostream>
#include <vector>

bool canDistributeShirts(int n, int m, int c, std::vector<std::vector<int>>& shirts, std::vector<int>& sizesAvailable) {
    if (c == m) {
        return true;
    }
    // try giving the first size that fits
    if (sizesAvailable[shirts[c][0]] > 0) {
        sizesAvailable[shirts[c][0]]--;
        if (canDistributeShirts(n, m, c + 1, shirts, sizesAvailable)) {
            return true;
        }
        sizesAvailable[shirts[c][0]]++;
    }
    // try giving the second size that fits
    if (sizesAvailable[shirts[c][1]] > 0) {
        sizesAvailable[shirts[c][1]]--;
        if (canDistributeShirts(n, m, c + 1, shirts, sizesAvailable)) {
            return true;
        }
        sizesAvailable[shirts[c][1]]++;
    }
    return false;
}

int convertSizeToNumber(std::string size) {
    if (size == "XS") {
        return 0;
    } else if (size == "S") {
        return 1;
    } else if (size == "M") {
        return 2;
    } else if (size == "L") {
        return 3;
    } else if (size == "XL") {
        return 4;
    } else if (size == "XXL") {
        return 5;
    }
    return -1;
}

int main() {
    int cases;
    std::cin >> cases;
    while (cases--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::vector<int>> shirts(m, std::vector<int>(2));
        std::vector<int> sizesAvailable(6);
        for (int i = 0; i < 6; i++) {
            sizesAvailable[i] = n / 6;
        }

        for (int i = 0; i < m; i++) {
            std::string a, b;
            std::cin >> a >> b;
            shirts[i][0] = convertSizeToNumber(a);
            shirts[i][1] = convertSizeToNumber(b);
        }
        if (canDistributeShirts(n, m, 0, shirts, sizesAvailable)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}