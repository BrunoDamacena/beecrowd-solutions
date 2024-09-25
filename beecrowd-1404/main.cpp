#include <iostream>
#include <vector>

bool canCapture(int fromI, int fromJ, int toI, int toJ, std::vector<std::vector<int>>& board, int n, int m) {
    // cant go out of bounds
    if (toI < 0 || toJ < 0 || toI >= n || toJ >= m) {
        return false;
    }
    // cant jump to an occupied square
    if (board[toI][toJ] != 0) {
        return false;
    }
    int overI = (fromI + toI)/2;
    int overJ = (fromJ + toJ)/2;
    // can only jump over an enemy piece
    return board[overI][overJ] == 2;
}

int checkCaptures(int i, int j, std::vector<std::vector<int>>& board, int n, int m) {
    int ans = 0;
    // Let's try capturing on all four diagonals
    // now doing it on a loop and avoiding the unnecessary aux matrix
    // optimize it, baby
    for (int di = -2; di <= 2; di += 4) {
        for (int dj = -2; dj <= 2; dj += 4) {
            if (canCapture(i, j, i + di, j + dj, board, n, m)) {
                board[i][j] = 0;
                board[i + di / 2][j + dj / 2] = 0;
                board[i + di][j + dj] = 1;
                ans = std::max(ans, 1 + checkCaptures(i + di, j + dj, board, n, m));
                board[i][j] = 1;
                board[i + di / 2][j + dj / 2] = 2;
                board[i + di][j + dj] = 0;
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    while (n != 0 && m != 0) {
        std::vector<std::vector<int>> board(n, std::vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = i % 2; j < m ; j += 2) {
                std::cin >> board[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = (i % 2); j < m; j += 2) {
                if (board[i][j] == 1) {
                    ans = std::max(ans, checkCaptures(i, j, board, n, m));
                }
            }
        }

        std::cout << ans << std::endl;
        std::cin >> n >> m;
    }
    return 0;
}