class Solution {
public:
    long long minimumSteps(string s) {
        int count = 0;
        long long res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                count++;
            } else {
                res = res + count;
            }
        }
        return res;
    }
};