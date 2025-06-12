class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        nums.push_back(nums[0]);
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            res = max(res, abs(nums[i] - nums[i + 1]));
        }
        return res;
    }
};