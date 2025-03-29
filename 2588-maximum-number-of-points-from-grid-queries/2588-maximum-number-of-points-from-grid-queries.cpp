class Solution {
public:
    bool vis[1009][1009];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int dfs(vector<vector<int>>& g, int x, int y, int val) {
        if (val <= g[x][y]) {
            pq.push({g[x][y], {x, y}});
            return 0;
        }
        int ans=1;
        vis[x][y]=1;
        int dx[]={-1,+0,+0,+1};
        int dy[]={+0,-1,+1,+0};
        for (int i=0; i<4; i++) {
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if (nx < g.size() && ny < g[0].size() && ~nx && ~ny && !vis[nx][ny]) 
                ans+=dfs(g, nx, ny, val);
        }
        return ans;
    }
    vector<int> maxPoints(vector<vector<int>>& g, vector<int>& queries) {
        map<int, int> q;
        for (auto it:queries) q[it]=0;
        
        int prv=0;
        pq.push({g[0][0], {0, 0}});
        for (auto &[x, y]:q) {
            while (pq.size() && pq.top().first < x) {
                auto [a, b]=pq.top().second;
                pq.pop();
                if (!vis[a][b])
                    prv+=dfs(g, a, b, x);
            }
            y=prv;
        }

        vector<int> ans;
        for (auto it:queries) ans.push_back(q[it]);
        return ans;
    }
};