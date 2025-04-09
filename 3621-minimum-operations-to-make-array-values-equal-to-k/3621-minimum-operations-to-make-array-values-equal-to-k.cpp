class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> st(nums.begin(), nums.end());
        if (nums[0] < k) {
            return -1;
        }
        if (nums[0] == k) {
            return st.size() - 1;
        }

        return st.size();
    }
};