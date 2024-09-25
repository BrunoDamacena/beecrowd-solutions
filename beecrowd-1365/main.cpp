#include <iostream>
#include <vector>
#include <climits>

int seatClusterArea(int r, int c, int k, std::vector<std::vector<bool>>& seats) {
    int ans = INT_MAX;
    for (int i = 0; i < r; i++) {
        std::vector<int> dp(c, 0);
        for (int j = i; j < r; j++) {
            // update memory with seat availability for each row
            for (int l = 0; l < c; l++) {
                dp[l] += (int) seats[j][l];
            }
            // calculate the sum of available seats in the cluster
            int clusterSeats = 0;
            // iterate over columns to find max cluster area
            for (int l = 0, m = 0; m < c; m++) {
                clusterSeats += dp[m];
                // adjust left bound to satisfy the min seat requirement for the cluster
                while (l < m && (clusterSeats - dp[l]) >= k) {
                    clusterSeats -= dp[l];
                    l++;
                }	
                if (clusterSeats >= k) {
                    // if friends fits on this seat cluster, update answer with the smaller cluster possible
                    int base = m - l + 1;
                    int height = j - i + 1;
                    ans = std::min(ans, base * height);
                }
            }
        }
    }
    return ans;
}

int main() {
    int r, c, k;
    std::cin >> r >> c >> k;
    while (r != 0 && c != 0 && k != 0) {
        std::vector<std::vector<bool>> seatsAvailable(r, std::vector<bool>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char s;
                std::cin >> s;
                if (s == '.') {
                    seatsAvailable[i][j] = true;
                }
                else {
                    seatsAvailable[i][j] = false;
                }
            }
        }
        
        std::cout << seatClusterArea(r, c, k, seatsAvailable) << std::endl;
        std::cin >> r >> c >> k;
    }
    return 0;
}