class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> temp(nums.size(), -1);
        long long a = nums[nums.size() - 1];
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums[i] >= a) {
                temp[i] = a;
                a = nums[i];
            } else {
                temp[i] = a;
            }
        }
        a = nums[0];
        long long res = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (a > nums[i]) {
                res = max(res, (a - nums[i]) * temp[i]);
            } else {
                long long b = nums[i];
                a = max(a, b);
            }
        }
        return res;
    }
};