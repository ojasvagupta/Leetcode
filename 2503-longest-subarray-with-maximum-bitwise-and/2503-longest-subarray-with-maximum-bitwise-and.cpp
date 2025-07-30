class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int res = 0, curr = 0;

        for (int num : nums) {
            if (num == maxi) {
                curr++;
                res = max(res, curr);
            } else {
                curr = 0;
            }
        }

        return res;
    }
};
