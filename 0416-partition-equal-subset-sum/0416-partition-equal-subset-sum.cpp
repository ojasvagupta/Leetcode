class Solution {
public:
    bool clc(vector<int>& nums, int sum, int total, int i,vector<vector<int>>& memo) {
        if(sum==total)
        {
            return true;
        }
        if(i<0)
        {
            return false;
        }
        if(memo[i][sum]!=-1)
        {
            return memo[i][sum];
        }
        bool res = false;
        res = clc(nums, sum, total, i - 1,memo);
        res = res or clc(nums, sum + nums[i], total - nums[i], i - 1,memo);
        if(res)
        {
            memo[i][sum]=1;
        }
        else
        {
            memo[i][sum]=0;
        }
        return res;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        vector<vector<int>> memo(nums.size(),vector<int> (20001,-1));
        for (auto a : nums) {
            total += a;
        }
        return clc(nums, 0, total, nums.size()-1,memo);
    }
};