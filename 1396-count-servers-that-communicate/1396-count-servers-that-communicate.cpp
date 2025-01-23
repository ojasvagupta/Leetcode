class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<bool> row(grid.size(), false);
        vector<bool> col(grid[0].size(), false);
        for (int i = 0; i< grid.size(); i++) {
            bool x = false;
            int count = 0;
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
                if (count >= 2) {
                    x = true;
                    row[i] = x;
                    break;
                }
            }
        }
        for (int i = 0; i < grid[0].size(); i++) {
            bool x = false;
            int count = 0;
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][i] == 1) {
                    count++;
                }
                if (count >= 2) {
                    x = true;
                    col[i] = x;
                    break;
                }
            }
        }
        int res=0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]==1)
                {
                    if(row[i]==true or col[j]==true)
                    {
                        res++;
                    }
                }
                
            }
        }
        return res;
    }
};