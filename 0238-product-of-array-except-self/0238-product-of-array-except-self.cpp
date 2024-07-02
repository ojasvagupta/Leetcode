class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        vector<int> w;
        int left = 1;
        for (int i = 0; i < n; i++) {
            v.push_back(left);
            left = left * nums[i];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            w.push_back(right);
            right = right * nums[i];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = v[i] * w[n - 1 - i];
        }
        return nums;
    }
};