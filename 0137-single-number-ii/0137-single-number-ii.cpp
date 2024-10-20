class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            x = x ^ nums[i];
            if (!mp.count(nums[i])) {
                mp[nums[i]] = 1;
            } else {
                if (mp.count(nums[i]) && mp[nums[i]] < 2) {
                    mp[nums[i]]++;
                } else if (mp.count(nums[i]) && mp[nums[i]] == 2) {
                    x = x ^ nums[i];
                }
            }
        }
        return x;
    }
};