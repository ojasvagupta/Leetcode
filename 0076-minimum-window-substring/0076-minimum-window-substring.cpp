class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        if(s.size()<t.size())
        {
            return "";
        }
        for (int i = 0; i < t.size(); i++) {
            mp1[t[i]]++;
        }
        int i = 0;
        int n = mp1.size();
        int len = INT_MAX;
        int start = -1;
        int end = -1;
        unordered_set<char> st;
        for (int j = 0; j < s.size(); j++) {
            if (mp1.count(s[j])) {
                mp2[s[j]]++;
                if (mp2[s[j]] >= mp1[s[j]]) {
                    st.insert(s[j]);
                }
            }
            while (st.size() == n) {
                if (len > j - i + 1) {
                    len = j - i + 1;
                    start = i;
                    end = j;
                }
                if (mp2.count(s[i])) {
                    mp2[s[i]]--;
                    if (mp2[s[i]] < mp1[s[i]]) {
                        st.erase(s[i]);
                    }
                }
                i++;
            }
        }
        string res = "";
        if (start == -1 || end == -1) {
            return res;
        }
        res = res + s.substr(start, end - start + 1);
        return res;
    }
};