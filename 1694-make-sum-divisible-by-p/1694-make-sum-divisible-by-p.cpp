class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> mp;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }
        if (sum % p == 0) {
            return 0;
        }
        mp[0] = -1;
        int target = sum % p;
        int curr = 0;
        int minlen = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            curr = (curr + nums[i]) % p;

            int prev = (curr - target + p) % p;
            if (mp.count(prev)) {
                int len = i - mp[prev];
                minlen = min(len, minlen);
            }
            mp[curr] = i;
        }
        if(minlen!=nums.size())
        {
            return minlen;
        }

        return -1;
    }
};