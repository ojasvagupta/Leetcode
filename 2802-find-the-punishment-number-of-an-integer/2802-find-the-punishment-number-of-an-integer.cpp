class Solution {
public:
    bool check(int pro, int sum, int& prev) {
        if (sum == prev && pro == 0) {
            return true;
        }
        int i = 10;
        bool res = false;
        int mul = pro;
        while (mul > 0) {
            int temp = pro % i;
            mul = pro / i;
            res = res || check(mul, sum + temp, prev);
            i = i * 10;
        }
        return res;
    }
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int pro = i * i;
            if (check(pro, 0, i)) {
                res = res + pro;
            }
        }
        return res;
    }
};