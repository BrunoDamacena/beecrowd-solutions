#include <iostream>
#include <vector>

// sum two arrays as ints using first grade math carry one logic
// because it overflows with unsigned long long :(
void addNumber(std::vector<int>& result, const std::vector<int>& add) {
    int carry = 0;
    int i = result.size() - 1;
    int j = add.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? result[i] : 0;
        int digit2 = (j >= 0) ? add[j] : 0;
        int sum = digit1 + digit2 + carry;

        if (i >= 0) {
            result[i] = sum % 10;
        } else {
            result.insert(result.begin(), sum % 10);
        }

        carry = sum / 10;
        i--;
        j--;
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;
    while(n != 0 && k != 0) {
        std::vector<int> v(n);
        for (int i = 0; i < n; i++) {
            std::cin >> v[i];
        }
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>> (k + 1, std::vector<int> (1, 0)));
        for (int i = 0; i < n; i++) {
            dp[i][1] = {1};
        }

        std::vector<int> ans = {0};
        for (int i = 0; i < n; i++) {
            // Iterate over previous indices
            for (int j = 0; j < i; j++) {
                if (v[i] > v[j]) {
                    // update dp[i][c] for all combinations from 2 to k
                    for (int c = 2; c <= k; c++) {
                        addNumber(dp[i][c], dp[j][c - 1]);
                    }
                }
            }
            // update the amount of combinations from i to n
            addNumber(ans, dp[i][k]);
        }
        // print result from number array
        for (int i = 0; i < ans.size(); i++) {
            std::cout << ans[i];
        }
        std::cout << std::endl;
        std::cin >> n >> k;
    }
    
    return 0;
}