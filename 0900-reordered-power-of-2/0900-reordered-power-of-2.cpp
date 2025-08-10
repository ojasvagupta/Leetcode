class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int i = 1;
        vector<vector<vector<int>>> v(10);
        while (i <= 1e9) {
            vector<int> w(10, 0);
            int x = i;
            int c = 0;
            while (x > 0) {
                c++;
                w[x % 10]++;
                x = x / 10;
            }
            v[c - 1].push_back(w);
            i = i * 2;
        }
        vector<int> z(10, 0);
        int count = 0;
        while (n > 0) {
            count++;
            z[n % 10]++;
            n = n / 10;
        }
        for (vector<int> a : v[count - 1]) {
            if (a == z) {
                return true;
            }
        }
        return false;
    }
};