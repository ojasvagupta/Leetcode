class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& mp, vector<int>& vis, int i) {
        vis[i] = -1; // mark as visiting
        for (auto a : mp[i]) {
            if (vis[a] == -1) { // cycle detected
                return false;
            }
            if (vis[a] == 0) { // not visited
                if (!dfs(mp, vis, a)) {
                    return false;
                }
            }
        }
        vis[i] = 1; // mark as visited
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        vector<int> vis(numCourses, 0);

        // Build the graph
        for (auto i : prerequisites) {
            mp[i[1]].push_back(i[0]);
        }

        // Check for cycles in the graph
        for (int i = 0; i < numCourses; ++i) {
            if (vis[i] == 0) {
                if (!dfs(mp, vis, i)) {
                    return false;
                }
            }
        }

        return true;
    }
};
