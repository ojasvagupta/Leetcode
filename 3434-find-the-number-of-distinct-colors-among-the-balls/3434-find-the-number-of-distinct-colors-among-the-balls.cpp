class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> v;
        unordered_map<int, int> colors;
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (!v.count(a)) {
                v[a] = b;
                if (!colors.count(b)) {
                    colors[b] = 1;
                } else {
                    colors[b]++;
                }
            } else {
                if (v[a] != b) {
                    if (colors[v[a]] == 1) {
                        colors.erase(v[a]);
                    } else {
                        colors[v[a]]--;
                    }
                    v[a] = b;
                    if (colors.count(b)) {
                        colors[b]++;
                    } else {
                        colors[b] = 1;
                    }
                }
            }
            res.push_back(colors.size());
        }
        return res;
    }
};