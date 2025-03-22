class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& mp,
             unordered_set<int>& vis, vector<int>& component) {
        vis.insert(node);
        component.push_back(node);
        for (int neighbor : mp[node]) {
            if (!vis.count(neighbor)) {
                dfs(neighbor, mp, vis, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for (auto& edge : edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> vis;
        int res = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis.count(i)) {
                vector<int> component;
                dfs(i, mp, vis, component);
                int compSize = component.size();
                bool isComplete = true;

                for (int node : component) {
                    if (mp[node].size() != compSize - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete)
                    res++;
            }
        }

        return res;
    }
};
