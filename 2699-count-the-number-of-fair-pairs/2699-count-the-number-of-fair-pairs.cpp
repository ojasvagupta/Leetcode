class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            // Find the first position where nums[i] + nums[a] >= lower
            int a = lower_bound(nums.begin() + i + 1, nums.end(), lower - x) - nums.begin();
            // Find the first position where nums[i] + nums[b] > upper
            int b = upper_bound(nums.begin() + i + 1, nums.end(), upper - x) - nums.begin() - 1;

            if (a <= b) {
                res += (b - a + 1);  // Add the number of valid pairs for this i
            }
        }

        return res;
    }
};
