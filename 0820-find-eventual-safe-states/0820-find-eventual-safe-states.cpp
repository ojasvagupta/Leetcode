class Solution {
public:
    bool clc(vector<vector<int>>& graph, vector<int>& term, int i) {
        bool res = false;
        if (graph[i].size() == 0) {
            return true;
        }
        if (term[i] == 2) {
            return true;
        }
        term[i] = 1;
        for (int a : graph[i]) {
            if (term[a] == 1) {
                return false;
            }
            bool check = false;
            res = check || clc(graph, term, a);
            if (!res) {
                return false;
            }
        }
        if (res) {
            term[i] = 2;
        }
        return res;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> term(n, 0);
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (clc(graph, term, i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};