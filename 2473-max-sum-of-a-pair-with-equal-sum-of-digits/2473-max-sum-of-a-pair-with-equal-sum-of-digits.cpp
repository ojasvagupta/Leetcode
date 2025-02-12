class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int res = -1;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> v;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int a = nums[i];
            int sum = 0;
            while (a > 0) {
                sum = sum + a % 10;
                a = a / 10;
            }
            v.push_back(sum);
            if (!mp.count(sum)) {
                mp[sum] = nums[i];
            } else {
                res = max(res, mp[sum] + nums[i]);
            }
        }
        return res;
    }
};