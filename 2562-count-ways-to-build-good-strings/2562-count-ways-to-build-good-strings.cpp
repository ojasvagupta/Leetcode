class Solution {
public:
    int MOD = 1e9 + 7;

    int calci(int low, int high, int zero, int one, int count, vector<int>& memo) {
        if (count > high) {
            return 0; // Exceeds the allowed range
        }
        if (memo[count] != -1) {
            return memo[count]; // Use memoized result
        }

        int res = 0;
        // If the current count is within the range, consider it as a valid string
        if (count >= low) {
            res = 1;
        }

        // Add recursive results for appending zero and one
        res = (res + calci(low, high, zero, one, count + zero, memo)) % MOD;
        res = (res + calci(low, high, zero, one, count + one, memo)) % MOD;

        // Memoize the result
        memo[count] = res;
        return res;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> memo(high + 1, -1); // Initialize memoization table
        return calci(low, high, zero, one, 0, memo);
    }
};
