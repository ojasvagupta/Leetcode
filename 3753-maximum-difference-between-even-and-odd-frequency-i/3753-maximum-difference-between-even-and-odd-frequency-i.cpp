class Solution {
public:
    int maxDifference(string s) {
        vector<int> v(26, 0);
        int omax = 0;
        int emin = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (v[i] % 2 == 1 && v[i] > omax) {
                omax = v[i];
            }
            if (v[i] % 2 == 0 && v[i] < emin && v[i] != 0) {
                emin = v[i];
            }
        }
        return omax - emin;
    }
};