class Solution {
public:
    int maxSquareMemo(vector<vector<char>>& matrix, int i, int j,
                      vector<vector<int>>& dp) {
        if (i >= matrix.size() || j >= matrix[0].size() ||
            matrix[i][j] == '0') {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int right = maxSquareMemo(matrix, i, j + 1, dp);
        int down = maxSquareMemo(matrix, i + 1, j, dp);
        int diag = maxSquareMemo(matrix, i + 1, j + 1, dp);
        return dp[i][j] = 1 + min({right, down, diag});
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int max_side = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    max_side = max(max_side, maxSquareMemo(matrix, i, j, dp));
                }
            }
        }
        return max_side * max_side;
    }
};