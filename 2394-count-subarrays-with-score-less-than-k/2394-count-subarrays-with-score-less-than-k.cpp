class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        vector<long long> pre(nums.size() + 1, 0);
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            pre[i + 1] = sum;
        }
        int i = 0;
        int j = 0;
        long long count = 0;
        while (j < nums.size()) {
            long long score = (pre[j + 1] - pre[i]) * (j + 1 - i);
            while (score >= k) {
                count = count + (nums.size() - j);
                i++;
                score = (pre[j + 1] - pre[i]) * (j + 1 - i);
            }
            j++;
        }
        long long v = 1LL * n * (n + 1) / 2;
        return v - count;
    }
};