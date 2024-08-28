class Solution {
public:
    void countIslands(vector<vector<int>>& grid2, vector<vector<bool>>& vis,
                      int m, int n, vector<vector<int>>& set) {
        if (m > grid2.size() - 1 || n > grid2[0].size() - 1 ||
            vis[m][n] == true || m < 0 || n < 0 || grid2[m][n] == 0) {
            return;
        }
        vis[m][n] = true;
        set.push_back({m, n});
        vector<pair<int,int>> v = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto a : v) {
            countIslands(grid2, vis, m + a.first, n + a.second, set);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int count = 0;
        vector<vector<bool>> vis(grid2.size(),
                                 vector<bool>(grid2[0].size(), false));
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j] == 1 && vis[i][j] == false) {
                    vector<vector<int>> set;
                    count++;
                    countIslands(grid2, vis, i, j, set);
                    for (auto b : set) {
                        if (grid1[b[0]][b[1]] == 0) {
                            count--;
                            break;
                        }
                    }
                }
            }
        }
        return count;
    }
};