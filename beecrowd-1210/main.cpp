#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

void calc(int n, int m, int p, const std::vector<int>& c, const std::vector<int>& v, std::vector<std::vector<int>>& dp, std::vector<std::vector<int>>& backtracking) {
    for (int curr = n; curr >= 1; curr--) {
        for (int age = 1; age <= m; age++) {
            int changeCost = c[0] + p - v[age - 1] + dp[curr + 1][1];
            int keepCost = INT_MAX;
            if (age < m) {
                keepCost = c[age] + dp[curr + 1][age + 1];
            }

            if (changeCost <= keepCost) {
                backtracking[curr][age] = 1;
            } else {
                backtracking[curr][age] = age + 1;
            }
            dp[curr][age] = std::min(changeCost, keepCost);
        }
    }
}

int main() {
    int n, i, m, p;
    while (std::cin >> n >> i >> m >> p) {
        std::vector<int> c(m), v(m);
        for (int j = 0; j < m; j++) {
            std::cin >> c[j];
        }
        for (int j = 0; j < m; j++) {
            std::cin >> v[j];
        }

        std::vector<std::vector<int>> dp(n + 2, std::vector<int>(m + 1, 0));
        std::vector<std::vector<int>> backtracking(n + 2, std::vector<int>(m + 1));
        calc(n, m, p, c, v, dp, backtracking);

        std::cout << dp[1][i] << std::endl;

        int t = 1;
        int age = i;
        bool firstExchange = true;
        for (int j = 1; j <= n; j++) {
            if (backtracking[j][age] == 1) {
                if (!firstExchange) {
                    std::cout << " ";
                }
                std::cout << j;
                firstExchange = false;
            }
            age = backtracking[j][age];
        }
        if (firstExchange) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << std::endl;
        }
    }
    return 0;
}
