class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        unordered_map<string, vector<string>> mp;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (!mp.count(s)) {
                mp[s].push_back(strs[i]);
            } else {
                mp[s].push_back(strs[i]);
            }
        }
        for (auto i : mp) {
            v.push_back(i.second);
        }
        return v;
    }
};