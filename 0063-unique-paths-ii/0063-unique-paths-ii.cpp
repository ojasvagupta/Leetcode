class Solution {
public:
    int clc(vector<vector<int>>& obstacleGrid, int i, int j,
            vector<vector<int>>& memo) {

        if (obstacleGrid[i][j] == 1) {
            return 0;
        }
        if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1) {
            return 1;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int res = 0;
        if (j + 1 < obstacleGrid[0].size()) {
            res = clc(obstacleGrid, i, j + 1, memo);
        }
        if (i + 1 < obstacleGrid.size()) {
            res = res + clc(obstacleGrid, i+1, j, memo);
        }
        memo[i][j] = res;
        return res;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> memo(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return clc(obstacleGrid, 0, 0, memo);
    }
};