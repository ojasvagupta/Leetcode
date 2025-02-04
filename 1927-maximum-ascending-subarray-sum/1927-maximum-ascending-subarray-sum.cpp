class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int temp = nums[0];
        int res = temp;
        int out = temp;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > temp) {
                res = res + nums[i];
                out = max(out, res);
                temp = nums[i];
            } else {
                temp = nums[i];
                res = nums[i];
            }
        }
        return out;
    }
};