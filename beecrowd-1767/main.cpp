#include <iostream>
#include <vector>
#include <algorithm>

struct KnapsackResult {
    int toys;
    int weight;
    int toysOut;
};

KnapsackResult knapsack(const std::vector<std::pair<int, int>>& items, int n, int w) {
    // using dynamic programming to solve the knapsack problem
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++) {
        int weight = items[i - 1].second;
        int value = items[i - 1].first;
        for (int j = 1; j <= w; j++) {
            if (weight <= j) { // if fits the knapsack
                // solution is max value between including or not the toy on the sack
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight] + value);
            } else { // else, it doesnt fit, solution still the same
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // backtracking solution
    int weight = 0;
    int toysOut = n;
    int remainingWeight = w;

    for (int i = n; i > 0; --i) {
        if (dp[i][remainingWeight] != dp[i - 1][remainingWeight]) {
            weight += items[i - 1].second;
            remainingWeight -= items[i - 1].second;
            toysOut--;
        }
    }

    return {dp[n][w], w - remainingWeight, toysOut};
}

int main() {
    int n;
    std::cin >> n;
    while(n--) {
        int pac, total = 0;
        std::cin >> pac;
        std::vector<std::pair<int, int>> toys(pac);
        for (int i = 0; i < pac; i++) {
            std::pair<int, int> toy;
            std::cin >> toy.first >> toy.second;
            toys[i] = toy;
        }
        KnapsackResult result = knapsack(toys, pac, 50);
        std::cout << result.toys << " brinquedos" << std::endl;
        std::cout << "Peso: " << result.weight << " kg" << std::endl;
        std::cout << "sobra(m) " << result.toysOut << " pacote(s)" << std::endl << std::endl;
    }
    return 0;
}