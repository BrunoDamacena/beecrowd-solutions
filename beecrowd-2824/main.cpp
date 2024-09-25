#include <iostream>
#include <vector>
#include <algorithm>

int longestCommonSubstring(const std::string& a, const std::string& b) {
    int m = a.length();
    int n = b.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Fill the dp array using dynamic programming
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // return the length of the longest common subsequence
    return dp[m][n];
}

int main() {
    std::string search, article;
    std::cin >> search >> article;
    std::cout << longestCommonSubstring(search, article) << std::endl;
    return 0;
}
