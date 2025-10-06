class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // dist[i][j] = minimum possible "time" to reach (i, j)
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Min-heap: {time, row, col}
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        // Directions: down, up, right, left
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [t, x, y] = pq.top();
            pq.pop();

            // If we reached destination, return the answer
            if (x == n-1 && y == n-1) return t;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    int newT = max(t, grid[nx][ny]);
                    if (newT < dist[nx][ny]) {
                        dist[nx][ny] = newT;
                        pq.push({newT, nx, ny});
                    }
                }
            }
        }
        return -1; // should never reach here
    }
};
