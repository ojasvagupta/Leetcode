class Solution {
public:
int clc(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& memo)
{
    if(i==grid.size()-1 && j==grid[0].size()-1)
    {
        return grid[i][j];
    }
    int sum=INT_MAX;
    if(memo[i][j]!=-1)
    {
        return memo[i][j];
    }
    if(j+1<grid[0].size())
    {
        sum=min(sum,grid[i][j]+clc(i,j+1,grid,memo));
    }
    if(i+1<grid.size())
    {
        sum=min(sum,(grid[i][j]+clc(i+1,j,grid,memo)));
    }
    return memo[i][j]=sum;
}
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(),vector<int>(grid[0].size(),-1));
        return clc(0,0,grid,memo);
        
    }
};