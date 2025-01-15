class Solution {
public:
    vector<vector<int>> memo;

    bool helper(const string &s1, const string &s2, const string &s3, int i, int j, int k) {
        if (k == s3.size()) {
            return i == s1.size() && j == s2.size();
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        bool res = false;
        if (i < s1.size() && s1[i] == s3[k]) {
            res = res || helper(s1, s2, s3, i + 1, j, k + 1);
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            res = res || helper(s1, s2, s3, i, j + 1, k + 1);
        }

        memo[i][j] = res;
        return res;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        memo = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return helper(s1, s2, s3, 0, 0, 0);
    }
};
