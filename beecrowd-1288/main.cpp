#include <iostream>
#include <vector>

int main() {
    int c;
    std::cin >> c;
    while (c--) {
        int n, k, r;
        std::cin >> n;
        std::vector<std::pair<int, int>> projectiles(n);

        for (int i = 0; i < n; i++) {
            std::pair<int, int> p;
            std::cin >> p.first >> p.second;
            projectiles[i] = p;
        }
        std::cin >> k >> r;
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            int power = projectiles[i - 1].first;
            int weight = projectiles[i - 1].second;
            for (int j = 1; j <= k; j++) {
                if (weight <= j) {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight] + power);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][k] < r) {
            std::cout << "Falha na missao" << std::endl;
        }
        else {
            std::cout << "Missao completada com sucesso" << std::endl;
        }
    }
    return 0;
}