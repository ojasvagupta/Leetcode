class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total_sum = 0;
        long long left_sum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            total_sum += nums[i];
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            left_sum = left_sum + nums[i];
            long long right_sum = total_sum - left_sum;
            if (left_sum >= right_sum) {
                res++;
            }
        }
        return res;
    }
};