#include <iostream>
#include <vector>
#include <climits>

// for some reason, it doesnt works with INT_MAX
#define IMPOSSIBLE 1000000 // 1000 maximum spells * 1000 maximum mana for each spell

int minimizeMana(int n, int p, int i, std::vector<std::pair<int, int>>& spells, std::vector<std::vector<int>>& dp) {
    if (p <= 0) { // no need to use more spells
        return 0;
    }

    if (i == n) { // already used all spells, impossible
        return IMPOSSIBLE;
    }

    if (dp[p][i] != -1) { // already calculated, return from table
        return dp[p][i];
    }

    int d = spells[i].first;
    int m = spells[i].second;

    // this case is the minimum value of using this spell or not
    dp[p][i] = std::min(m + minimizeMana(n, p - d, i + 1, spells, dp), minimizeMana(n, p, i + 1, spells, dp));
    return dp[p][i];
}

int main() {
    int n, p;
    while (std::cin >> n >> p) {
        std::vector<std::pair<int, int>> spells(n);
        for (int i = 0; i < n; i++) {
            int d, m;
            std::cin >> d >> m;
            spells[i] = {d, m};
        }
        
        std::vector<std::vector<int>> dp(p + 1, std::vector<int>(n + 1, -1));
        int min = minimizeMana(n, p, 0, spells, dp);
        if (min == IMPOSSIBLE) {
            min = -1; // If it's impossible to deal damage greater than 0 with available spells.
        }
        std::cout << min << std::endl;
    }
    return 0;
}