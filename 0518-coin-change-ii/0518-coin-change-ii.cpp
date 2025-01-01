class Solution {
public:
    int calc(int amount, vector<int>& coins, vector<vector<int>>& memo, int idx) {
        if (amount == 0) {
            return 1; // Found a valid way
        }
        if (amount < 0 || idx >= coins.size()) {
            return 0; // No valid way
        }
        if (memo[idx][amount] != -1) {
            return memo[idx][amount]; // Use cached result
        }

        // Include the current coin or skip it
        int include = calc(amount - coins[idx], coins, memo, idx);
        int exclude = calc(amount, coins, memo, idx + 1);

        memo[idx][amount] = include + exclude;
        return memo[idx][amount];
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return calc(amount, coins, memo, 0);
    }
};
