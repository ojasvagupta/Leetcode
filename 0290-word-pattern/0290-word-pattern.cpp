class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string a = "";
        unordered_map<char, string> mp;
        unordered_map<string, char> mp1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ' && i < (s.size() - 1)) {
                a = a + s[i];
            } else if (i == (s.size() - 1)) {
                a = a + s[i];
                v.push_back(a);
            } else {
                v.push_back(a);
                a = "";
            }
        }
        if (pattern.length() != v.size()) {
            return false;
        }
        for (int i = 0; i < pattern.size(); i++) {
            if (mp.count(pattern[i]) == 1) {
                if (mp[pattern[i]] != v[i]) {
                    return false;
                }

            } else {
                mp[pattern[i]] = v[i];
            }

            if (mp1.count(v[i]) == 1) {
                if (mp1[v[i]] != pattern[i]) {
                    return false;
                }

            } else {
                mp1[v[i]] = pattern[i];
            }
        }
        return true;
    }
};