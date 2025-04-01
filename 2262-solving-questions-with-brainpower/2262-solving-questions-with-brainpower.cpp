class Solution {
public:
    long long solve(vector<vector<int>>& questions, int a, vector<long long>& vis) {
        if (a >= questions.size()) {
            return 0;
        }
        if (vis[a] != -1) { // Use -1 instead of 0 to distinguish between uncomputed values.
            return vis[a];
        }

        // Option 1: Solve this question
        long long take = questions[a][0] + solve(questions, a + questions[a][1] + 1, vis);

        // Option 2: Skip this question
        long long skip = solve(questions, a + 1, vis);

        return vis[a] = max(take, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> vis(questions.size(), -1);
        return solve(questions, 0, vis);
    }
};
