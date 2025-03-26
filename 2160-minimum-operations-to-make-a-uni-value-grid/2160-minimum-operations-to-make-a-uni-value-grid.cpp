class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mead = nums[n/2];
        int res = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] - nums[0]) % x != 0) {
                return -1;
            }
            res = res + abs(mead - nums[i]) / x;
        }
        return res;
    }
};