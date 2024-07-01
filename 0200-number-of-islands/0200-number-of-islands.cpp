class Solution {
    bool isSafe(int newi, int newj, int m, int n) {
        return (newi >= 0 && newi < m && newj >= 0 && newj < n);
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i,
             int j, int m, int n) {
        vis[i][j] = true;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int k = 0; k < 4; k++) {
            int newi = i + dir[k][0];
            int newj = j + dir[k][1];
            if (isSafe(newi, newj, m, n) && grid[newi][newj] == '1' &&
                vis[newi][newj] == false) {
                dfs(grid, vis, newi, newj, m, n);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && vis[i][j] == false) {
                    res = res + 1;
                    dfs(grid, vis, i, j, m, n);
                }
            }
        }
        return res;
    }
};