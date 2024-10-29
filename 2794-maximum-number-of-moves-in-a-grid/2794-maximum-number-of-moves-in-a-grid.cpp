class Solution {
public:
void count(vector<vector<int>>& grid,int i,int j,int nums,int cnt,int& res,vector<vector<int>>& memo)
{
    if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]<=nums)
    {
        return;
    }
    if(memo[i][j]!=0)
    {
        cnt=memo[i][j];
        res=max(cnt,res);
        return;
    }
    nums=grid[i][j];
    count(grid,i-1,j+1,nums,cnt+1,res,memo);
    count(grid,i,j+1,nums,cnt+1,res,memo);
    count(grid,i+1,j+1,nums,cnt+1,res,memo);
    res=max(res,cnt);
    memo[i][j]=res;
}
    int maxMoves(vector<vector<int>>& grid) {
        int res=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> memo(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++)
        {
            int cnt=0;
            count(grid,i,0,-1,cnt,res,memo);
            res=max(res,cnt);
        }
        return res;
        
    }
};