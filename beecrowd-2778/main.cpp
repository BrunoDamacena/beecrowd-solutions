#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Struct to represent a cell in the matrix
struct Cell {
    int x, y, cost;
    Cell(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost) {}
};

int minCostPath(const vector<vector<int>>& matrix, int X, int Y) {
    int N = matrix.size();
    int M = matrix[0].size();

    // Initialize dp table
    vector<vector<int>> dp(N, vector<int>(M, INF));

    // Custom comparator for priority queue
    auto compare = [](const Cell& a, const Cell& b) {
        return a.cost > b.cost;
    };

    // Priority queue to store cells based on their cost
    priority_queue<Cell, vector<Cell>, decltype(compare)> pq(compare);

    // Initialize starting cell
    dp[0][0] = matrix[0][0];
    pq.push(Cell(0, 0, matrix[0][0]));

    // Array to store visited cells
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    // Arrays to represent movements
    int dx[] = {1, 0, 0};
    int dy[] = {0, 1, -1};

    while (!pq.empty()) {
        Cell current = pq.top();
        pq.pop();

        int x = current.x;
        int y = current.y;

        // Check if reached destination
        if (x == N - 1 && y == M - 1) {
            return dp[x][y];
        }

        // Mark current cell as visited
        visited[x][y] = true;

        // Explore neighbors
        for (int k = 0; k < 3; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
                // Update cost if constraints are satisfied
                if (matrix[nx][ny] >= 0 &&
                    (matrix[nx][ny] == 0 ? current.cost < X : current.cost <= Y)) {
                    int new_cost = current.cost + matrix[nx][ny];
                    if (new_cost < dp[nx][ny]) {
                        dp[nx][ny] = new_cost;
                        pq.push(Cell(nx, ny, new_cost));
                    }
                }
            }
        }
    }

    // If destination is not reachable
    return -1;
}

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    while (N > 0 || M > 0) {

        vector<vector<int>> matrix(N, vector<int>(M));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }

        int result = minCostPath(matrix, X, Y);

        if (result == -1) {
            cout << "Impossivel" << endl;
        } else {
            cout << result << endl;
        }

        cin >> N >> M >> X >> Y;
    }


    return 0;
}
