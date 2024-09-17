class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        unordered_map<string, int> mp1;
        vector<string> res;
        int i = 0;
        while (i < s1.size()) {
            string a = "";
            while (i < s1.size() && s1[i] != ' ') {
                a = a + s1[i];
                i++;
            }
            mp[a]++;
            i++;
        }
        i = 0;
        while (i < s2.size()) {
            string a = "";
            while (i < s2.size() && s2[i] != ' ') {
                a = a + s2[i];
                i++;
            }
            mp1[a]++;
            if (mp.count(a)) {
                mp[a] = 0;
                mp1[a] = 0;
            }
            i++;
        }
        for (auto a : mp) {
            if (a.second == 1) {
                res.push_back(a.first);
            }
        }
        for (auto a : mp1) {
            if (a.second == 1) {
                res.push_back(a.first);
            }
        }
        return res;
    }
};