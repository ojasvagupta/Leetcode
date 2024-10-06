class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int> &visited){
        visited[node] = 1;
        for(auto &it: adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // construct adjacency list
        vector<int> adj[n];
        for(auto it: invocations){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> visited(n,0);
        // mark all nodes as visited that are connected by k (directly or indirectly)
        dfs(k, adj, visited);
        
        bool suspicious = true;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                for(auto it: adj[i]){
                    // if an outside node invokes a node within group,
                    // then mark suspicious as false
                    if(visited[it]) suspicious = false;
                }
            }
        }
        vector<int> ans;
        if(suspicious){
            // remove nodes which are suspicious
            for(int i = 0; i < n; i++){
                if(!visited[i]) ans.push_back(i);
            }
        } else {
            // add all the nodes since there is no suspicious group
            for(int i = 0; i < n; i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
