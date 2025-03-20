class Solution {
public:
    void dfs(unordered_map<int, vector<pair<int, int>>>& mp, vector<bool>& vis, int node, int& weight) {
        vis[node] = true;
        for (auto& neighbor : mp[node]) {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;
            weight &= edgeWeight; // accumulate AND
            if (!vis[nextNode]) {
                dfs(mp, vis, nextNode, weight);
            }
        }
    }

    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
        int px = find(parent, x);
        int py = find(parent, y);
        if (px != py) {
            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
            } else {
                parent[py] = px;
                rank[px]++;
            }
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> parent(n), rank(n, 0);
        unordered_map<int, vector<pair<int, int>>> mp;

        // Initialize DSU
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        // Build graph and DSU
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            mp[u].emplace_back(v, w);
            mp[v].emplace_back(u, w); // bidirectional edge
            unite(parent, rank, u, v);
        }

        // Calculate bitwise AND of all edges in each component
        vector<bool> vis(n, false);
        unordered_map<int, int> componentWeight;

        for (int i = 0; i < n; ++i) {
            int root = find(parent, i);
            if (!vis[root]) {
                int weight = INT_MAX;
                dfs(mp, vis, root, weight);
                componentWeight[root] = weight;
            }
        }

        // Process queries
        vector<int> res;
        for (auto& q : query) {
            int u = q[0], v = q[1];
            if (find(parent, u) == find(parent, v)) {
                res.push_back(componentWeight[find(parent, u)]);
            } else {
                res.push_back(-1);
            }
        }

        return res;
    }
};
