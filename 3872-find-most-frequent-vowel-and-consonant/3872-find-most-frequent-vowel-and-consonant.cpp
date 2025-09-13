class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        int max1 = 0;
        int max2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                if (mp1.count(s[i])) {
                    mp1[s[i]]++;
                } else {
                    mp1[s[i]] = 1;
                }
                if (mp1[s[i]] > max1) {
                    max1 = mp1[s[i]];
                }
            } else {
                if (mp2.count(s[i])) {
                    mp2[s[i]]++;
                } else {
                    mp2[s[i]] = 1;
                }
                if (mp2[s[i]] > max2) {
                    max2 = mp2[s[i]];
                }
            }
        }

        return max1 + max2;
    }
};