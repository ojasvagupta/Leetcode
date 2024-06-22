
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;
        int maxsum = INT_MIN;
        for (int j = 0; j < n; j++) {
            sum = sum + nums[j];
            maxsum = max(maxsum, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxsum;
    }
};