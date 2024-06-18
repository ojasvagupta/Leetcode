class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ' && res == 0) {
                continue;
            } else if (s[i] == ' ' && res != 0) {
                break;
            } else if (s[i] != ' ')
                ++res;
        }
        return res;
    }
};