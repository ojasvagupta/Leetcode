class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Min-heap to store {cost, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0}); // {cost, row, col}

        // Cost array to track the minimum cost to each cell
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;

        // Directions: Right, Left, Down, Up
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty()) {
           vector<int> v = pq.top();
           int currCost=v[0];
           int x=v[1];
           int y=v[2];
            pq.pop();

            // If this cell has been processed with a smaller cost, skip it
            if (currCost > cost[x][y]) continue;

            // If we've reached the bottom-right corner, return the cost
            if (x == m - 1 && y == n - 1) return currCost;

            // Explore neighbors
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                // Check if the new position is within bounds
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int newCost = currCost + (i + 1 == grid[x][y] ? 0 : 1);

                    // If a smaller cost is found, update and push to the heap
                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;
                        pq.push({newCost, nx, ny});
                    }
                }
            }
        }

        return 0; // This line is never reached in a valid grid
    }
};
