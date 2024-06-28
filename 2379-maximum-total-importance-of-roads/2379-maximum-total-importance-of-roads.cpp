class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> mp;
        vector<vector<int>> v;
        for (long i = 0; i < n; i++) {
            mp[i] = 0;
        }
        for (long i = 0; i < roads.size(); i++) {
            long a = roads[i][0];
            long b = roads[i][1];
            mp[a]++;
            mp[b]++;
        }
        for (auto a : mp) {
            v.push_back({a.second, a.first});
        }
        sort(v.begin(), v.end());
        long long sum = 0;
        for (long i = 1; i <= v.size(); i++) {
            sum = sum + i * v[i - 1][0];
        }
        return sum;
    }
};