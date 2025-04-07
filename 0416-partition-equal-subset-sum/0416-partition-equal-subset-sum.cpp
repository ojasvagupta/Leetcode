class Solution {
public:
    bool clc(vector<int>& nums, int a, int sum,
             vector<vector<int>>& memo) {
        if (sum<0) {
            return false;
        }
        if (sum==0) {
            return true;
        }
        if (memo[a][sum] != -1) {
            if (memo[a][sum] == 1) {
                return true;
            } else {
                return false;
            }
        }
        bool res = false;
        for (int i = a; i < nums.size(); i++) {
            res = res || clc(nums, i + 1, sum-nums[i], memo);
            if (res) {
                break;
            }
        }
        if (res) {
            memo[a][sum] = 1;
        } else {
            memo[a][sum] = 0;
        }
        return res;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }
        vector<vector<int>> memo(nums.size() + 1, vector<int>(sum + 1, -1));
        sum = sum / 2;

        return clc(nums, 0,sum, memo);
    }
};