class Solution {
public:
    void clc(int a, string& pattern, string s, unordered_set<int>& st,
             bool& check, string& res) {
        if (check) {
            return;
        }
        if (a >= pattern.length()) {
            res = s;
            check = true;
            return;
        }
        for (int j = 1; j <= pattern.length()+1; j++) {
            if (pattern[a] == 'I' && j > (s[a] - '0') && !st.count(j)) {
                st.insert(j);
                clc(a + 1, pattern, s + to_string(j), st, check, res);
                st.erase(j);
            }
            if (pattern[a] == 'D' && j < (s[a] - '0') && !st.count(j)) {
                st.insert(j);
                clc(a + 1, pattern, s + to_string(j), st, check, res);
                st.erase(j);
            }
        }
    }
    string smallestNumber(string pattern) {
        string res = "";
        unordered_set<int> st;
        int k;
        if (pattern[0] == 'D') {
            k = INT_MAX;
        } else {
            k = 0;
        }
        bool check = false;
        for (int i = 1; i < 10; i++) {
            st.insert(i);
            clc(0, pattern, to_string(i), st, check, res);
            st.erase(i);
            if (check) {
                return res;
            }
        }

        return res;
    }
};