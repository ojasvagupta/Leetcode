class Solution {
public:
    int clc(vector<vector<int>>& grid, int i, int j,
            vector<vector<bool>>& vis,int islandID) {

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }
        if (vis[i][j]) {
            return 0;
        }
        vis[i][j] = true;
        if (grid[i][j] == 0) {
            return 0;
        }
        grid[i][j]=islandID;
        int res = 1;
        res = res + clc(grid, i + 1, j, vis ,islandID);
        res = res + clc(grid, i, j + 1, vis ,islandID);
        res = res + clc(grid, i - 1, j, vis ,islandID);
        res = res + clc(grid, i, j - 1, vis ,islandID);
        return res;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int islandID=2;
        unordered_map<int,int> mp;
        vector<vector<bool>> vis(
                        grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int val = clc(grid, i, j, vis,islandID);
                    mp[islandID]=val;
                    islandID++;
                }
            }
        }
        int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    unordered_set<int> st;
                    int temp=1;
                    if(i+1<grid.size())
                    {
                        temp=temp+mp[grid[i+1][j]];
                        st.insert(grid[i+1][j]);
                    }
                    if(j+1<grid[0].size() && !st.count(grid[i][j+1]))
                    {
                        temp=temp+mp[grid[i][j+1]];
                        st.insert(grid[i][j+1]);
                    }
                    if(i-1>=0 && !st.count(grid[i-1][j]))
                    {
                        temp=temp+mp[grid[i-1][j]];
                        st.insert(grid[i-1][j]);
                    }
                    if(j-1>=0 && !st.count(grid[i][j-1]) )
                    {
                        temp=temp+mp[grid[i][j-1]];
                    }
                    res=max(res,temp);
                }
            }
        }
        if(res==0)
        {
            return grid[0].size()*grid.size();
        }
        
        return res;
    }
};