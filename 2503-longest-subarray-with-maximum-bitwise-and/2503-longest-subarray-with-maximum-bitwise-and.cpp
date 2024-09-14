class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN;
        for (auto a : nums) {
            if (a > maxi) {
                maxi = max(maxi, a);
            }
        }
        int i = 0;
        int count = 0;
        int res = 0;
        while (i < nums.size()) {
            if (nums[i] == maxi) {
                count++;
            } else {
                count = 0;
            }
            res = max(res, count);
            i++;
        }
        return res;
    }
};