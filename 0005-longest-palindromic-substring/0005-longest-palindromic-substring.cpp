class Solution {
public:
    bool check(int st, int e, const string& s, vector<vector<int>>& memo) {
        if (memo[st][e] != -1) {
            return memo[st][e]; // Use stored result
        }
        int i = st, j = e;
        while (i < j) {
            if (s[i] != s[j]) {
                return memo[st][e] = 0; // Mark as not a palindrome
            }
            i++;
            j--;
        }
        return memo[st][e] = 1; // Mark as a palindrome
    }

    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }

        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]].push_back(i);
        }

        int maxLength = 0, start = -1;
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));

        for (const auto& entry : mp) {
            const vector<int>& indices = entry.second;
            for (int i = 0; i < indices.size(); i++) {
                for (int j = indices.size() - 1; j > i; j--) {
                    int len = indices[j] - indices[i] + 1;
                    if (len > maxLength && check(indices[i], indices[j], s, memo)) {
                        maxLength = len;
                        start = indices[i];
                    }
                }
            }
        }

        return start == -1 ? s.substr(0,1) : s.substr(start, maxLength);
    }
};
