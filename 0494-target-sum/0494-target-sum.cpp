class Solution {
public:
    int helper(vector<int>& nums, int target, int idx, int sum, vector<vector<int>>& memo, int offset) {
        if (idx == nums.size())
            return sum == target ? 1 : 0;
        if (memo[idx][sum + offset] != -1)
            return memo[idx][sum + offset];

        int subtract = helper(nums, target, idx + 1, sum - nums[idx], memo, offset);
        int add = helper(nums, target, idx + 1, sum + nums[idx], memo, offset);

        return memo[idx][sum + offset] = subtract + add;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > totalSum) return 0;

        int offset = totalSum; // To handle negative sums
        vector<vector<int>> memo(nums.size(), vector<int>(2 * totalSum + 1, -1));

        return helper(nums, target, 0, 0, memo, offset);
    }
};
