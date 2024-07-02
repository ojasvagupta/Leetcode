class Solution {
public:
    bool isSafe(int newi,int newj,int n,int m)
    {
        return(newi>=0 && newj>=0 && newi<n && newj<m);
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        grid[i][j]=1;
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++)
        {
            int newi=i+dir[k][0];
            int newj=j+dir[k][1];
            if(isSafe(newi,newj,n,m) && grid[newi][newj]==0)
            {
                dfs(newi,newj,n,m,grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) {
               dfs(i,0,n,m,grid);
            }
            if (grid[i][m - 1] == 0) {
                dfs(i,m-1,n,m,grid);
            }
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 0) {
                 dfs(0,i,n,m,grid);
            }
            if (grid[n - 1][i] == 0) {
                dfs(n-1,i,n,m,grid);
            }
        }

        int res=0;
        for( int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    res=res+1;
                     dfs(i,j,n,m,grid);
                }
            }
        }
        return res;
    }
};