class Solution {
public:
    int numberOfWays(int n, int x) {
        // Generate powers up to n
        vector<int> po;
        int i = 1;
        while (true) {
            long long val = 1;
            for (int j = 0; j < x; j++) val *= i; // integer power
            if (val > n) break;
            po.push_back((int)val);
            i++;
        }

        // DP array
        vector<int> memo(n + 1, 0);
        memo[0] = 1; // 1 way to make sum 0

        // Fill DP (similar to your nested loops but fixed)
        for (int a = po.size() - 1; a >= 0; a--) {
            for (int sum = n; sum >= po[a]; sum--) {
                memo[sum] =memo[sum]%1000000007 + memo[sum - po[a]]%1000000007;
            }
        }

        return memo[n]%1000000007;
    }
};
