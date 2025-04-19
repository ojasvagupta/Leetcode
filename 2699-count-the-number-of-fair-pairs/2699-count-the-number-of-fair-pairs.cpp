class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int l = lower - nums[i];
            int h = upper - nums[i];

            // Find first position >= l
            int left = i + 1, right = n - 1, a = n;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (nums[mid] >= l) {
                    a = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // Find last position <= h
            left = i + 1, right = n - 1;
            int b = i;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (nums[mid] <= h) {
                    b = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (a <= b) {
                res += (b - a + 1);
            }
        }

        return res;
    }
};
