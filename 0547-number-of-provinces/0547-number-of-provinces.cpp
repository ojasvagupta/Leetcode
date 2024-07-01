//1,1,0
//1,1,0
//0,0,1
class Solution {
    void dfs(vector<vector<int>>& isConnected,int n,int source, vector<bool>& vis)
    {
        for(int i=0;i<n;i++)
        {
            if(isConnected[source][i] && vis[i]==false)
            {
                vis[i]=true;
                dfs(isConnected,n,i,vis);
            }
        }
        
    }
    


public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,false);
        int e=0;
        int sum=0;
        for(int e=0;e<n;e++)
        {
            if(vis[e]==false){
            sum=sum+1;
            dfs(isConnected,n,e,vis);
            }
        }
        return sum;

        
        
    }
};