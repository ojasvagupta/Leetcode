class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        vector<vector<int>> v;
        int mini;int maxi;
        int count;
        while (i < nums.size()) {
            count = 0;
            vector<int> temp;
            mini = INT_MAX;
            maxi = INT_MIN;
            while (count < 3) {
                mini = min(mini, nums[i + count]);
                maxi = max(maxi, nums[i + count]);
                temp.push_back(nums[i + count]);
                count++;
            }
            if (maxi - mini <= k) {
                v.push_back(temp);
                i = i + 3;
            } else {
                return {};
            }
        }
        return v;
    }
};