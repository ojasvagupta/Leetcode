class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> mp;
        int res = 0;
        int a = n;
        while (res != 1) {
            res = 0;
            while (a > 0) {
                res = res + (a % 10) *( a % 10);
                a = a / 10;
            }
            if (mp.count(res)) {
                return false;
            }
            a = res;
            mp[res] = true;
        }
        if (res == 1) {
            return true;
        }
        return false;
    }
};