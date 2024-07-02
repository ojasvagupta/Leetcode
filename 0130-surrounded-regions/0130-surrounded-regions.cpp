class Solution {
public:
    void dfsa(int i, int j, int m, int n, vector<vector<bool>>& vis,
              vector<vector<char>>& board) {
        vis[i][j] = true;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int k = 0; k < 4; k++) {
            int newi = i + dir[k][0];
            int newj = j + dir[k][1];
            if (newi >= 0 && newj >= 0 && newi < n && newj < m &&
                board[newi][newj] == 'O' && !vis[newi][newj]) {
                dfsa(newi, newj, m, n, vis, board);
            }
        }
    }

    void dfs(int i, int j, int m, int n, vector<vector<bool>>& vis,
             vector<vector<char>>& board) {
        vis[i][j] = true;
        board[i][j] = 'X';
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int k = 0; k < 4; k++) {
            int newi = i + dir[k][0];
            int newj = j + dir[k][1];
            if (newi >= 0 && newj >= 0 && newi < n && newj < m &&
                board[newi][newj] == 'O' && !vis[newi][newj]) {
                dfs(newi, newj, m, n, vis, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfsa(i, 0, m, n, vis, board);
            if (board[i][m - 1] == 'O')
                dfsa(i, m - 1, m, n, vis, board);
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O')
                dfsa(0, i, m, n, vis, board);
            if (board[n - 1][i] == 'O')
                dfsa(n - 1, i, m, n, vis, board);
        }
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    dfs(i, j, m, n, vis, board);
                }
            }
        }
    }
};
