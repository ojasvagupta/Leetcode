class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(k * k, 0));
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] % k;
        }
        dp[0][nums[0]] = 1;
        int a = nums[0];
        vector<long long> res(k, 0);
        res[nums[0]]++;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < k; j++) {
                if (dp[i - 1][j] != 0) {
                    dp[i][(j * nums[i]) % k] =
                        dp[i][(j * nums[i]) % k] + dp[i - 1][j];
                        res[(j * nums[i]) % k]+=dp[i - 1][j];
                }
            }
            dp[i][nums[i]]++;
            res[nums[i]]++;
        }
        return res;
    }
};