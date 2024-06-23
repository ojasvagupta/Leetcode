class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.length();
        int res = 0;
        int count = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] == s[j]) {
                count++;
                j++;
            }
        }
        if (count == s.length()) {
            res = 1;
        }

        return res;
    }
};