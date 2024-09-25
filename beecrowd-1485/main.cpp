#include <iostream>
#include <vector>
#include <climits>

int maxProfit(int s, int b, std::vector<int>& roulette, std::vector<int>& balls) {
    std::vector<std::vector<int>> dp(2, std::vector<int>(s, 0));
    int min = INT_MAX;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = j * 2; k < s - 1 - 2 * (b - 1 - j); k++) {
                dp[j % 2][k] = (roulette[(i + k) % s] + roulette[(i + k + 1) % s]) * balls[j];
                if (j > 0)
                    dp[j % 2][k] += dp[(j - 1) % 2][k - 2];
                if (k != j * 2)
                    dp[j % 2][k] = std::min(dp[j % 2][k], dp[j % 2][k - 1]);
            }
        }
        min = std::min(min, dp[(b - 1) % 2][s - 2]);
    }
    return -min;
}

int main() {
    int s, b;
    std::cin >> s >> b;
    while (s != 0 && b != 0) {
        std::vector<int> roulette(s);
        for (int i = 0; i < s; i++) {
            std::cin >> roulette[i];
        }
        std::vector<int> balls(b);
        for (int i = 0; i < b; i++) {
            std::cin >> balls[i];
        }

        std::cout << maxProfit(s, b, roulette, balls) << std::endl;
        std::cin >> s >> b;
    }
    return 0;
}