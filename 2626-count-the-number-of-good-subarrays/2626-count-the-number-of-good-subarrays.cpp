class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long res = 0, count = 0;
        int i = 0;

        for (int j = 0; j < n; ++j) {
            // Add new element
            count += mp[nums[j]];
            mp[nums[j]]++;

            // Shrink from left while we have enough pairs
            while (count >= k) {
                // All subarrays from current i to the end (starting at i) are valid
                res += (n - j);
                count -= mp[nums[i]] - 1;
                mp[nums[i]]--;
                i++;
            }
        }

        return res;
    }
};
