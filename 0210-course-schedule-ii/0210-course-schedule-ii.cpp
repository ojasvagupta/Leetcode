class Solution {
public:
    bool dfs(int i, unordered_map<int, vector<int>>& mp, vector<int>& vis, vector<int>& res) {
        if (vis[i] == 1) return false; // A cycle is detected
        if (vis[i] == 2) return true;  // Already processed this node
        
        vis[i] = 1; // Mark as visiting
        if (mp.count(i)) {
            for (int a : mp[i]) {
                if (!dfs(a, mp, vis, res)) return false; // Cycle detected
            }
        }
        vis[i] = 2;  // Mark as fully visited
        res.push_back(i);  // Add to result after processing all dependencies
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        vector<int> vis(numCourses, 0); // 0 = not visited, 1 = visiting, 2 = fully visited
        vector<int> res;

        // Build adjacency list (prerequisite map)
        for (auto& p : prerequisites) {
            mp[p[1]].push_back(p[0]);
        }

        // Try to visit each course
        for (int i = 0; i < numCourses; ++i) {
            if (vis[i] == 0) {
                if (!dfs(i, mp, vis, res)) return {}; // Cycle detected, return empty result
            }
        }

        reverse(res.begin(), res.end()); // Reverse the result to get the correct order
        return res;
    }
};
