class Solution {
public:
long dfs(unordered_map<int, vector<int>>& mp,int i,int k,vector<int>& values,int vis,int & count)
{
    long sum=0;
    for(auto a : mp[i])
    {
        if(vis!=a)
        {
            sum=sum+dfs(mp,a,k,values,i,count);
        }
    }
    sum=sum+values[i];
    if(sum%k==0)
    {
        count++;
        sum=0;
    }
    return sum;
}




    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < edges.size(); i++) {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        int count = 0;
        int vis=-1;
        dfs(mp,0,k,values,vis,count);
        return count;
    }
};