#include <iostream>
#include <vector>
#include <algorithm>

int maxEvenNumbers(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = (arr[i] % 2 == 0) ? 1 : 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            if (l % 2 == 0) {
                dp[i][j] = std::max(dp[i + 1][j] + (arr[i] % 2 == 0), dp[i][j - 1] + (arr[j] % 2 == 0));
            } else {
                dp[i][j] = std::min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    int n;
    std::cin >> n;
    while (n != 0) {
        int size = 2 * n;
        std::vector<int> numbers(size);
        for (int i = 0; i < size; i++) {
            std::cin >> numbers[i];
        }

        std::cout << maxEvenNumbers(numbers) << std::endl;
        std::cin >> n;
    }
}