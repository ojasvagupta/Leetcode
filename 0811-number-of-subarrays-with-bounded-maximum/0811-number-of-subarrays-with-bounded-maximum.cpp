class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        long res = 0;
        int low = 0;
        long count = 0;
        int maxi = -1;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            if (maxi > right) {
                res = res + (count * (count + 1)) / 2;
                count = 0;
                maxi = -1;
            } else {
                count++;
                if (i == nums.size() - 1) {
                    res = res + (count * (count + 1)) / 2;
                }
            }
        }
        int diff = 0;
        int x = 0;
        while (x < nums.size()) {
            int cnt = 0;
            if (nums[x] < left) {
                while (x < nums.size() && nums[x] < left) {
                    cnt++;
                    x++;
                }
                diff = diff + (cnt * (cnt + 1)) / 2;
            } else {
                x++;
            }
        }
        if (res - diff < 0) {
            return 0;
        }
        return res - diff;
    }
};