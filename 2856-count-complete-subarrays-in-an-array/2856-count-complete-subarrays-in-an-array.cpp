class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        int n = st.size();
        st.clear();
        unordered_map<int, int> mp;
        int res = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i])) {
                mp[nums[i]]++;
            } else {
                mp[nums[i]] = 1;
            }
            st.insert(nums[i]);
            while (st.size() == n && j <= i) {
                res = res + (nums.size() - i);
                mp[nums[j]]--;
                if (mp[nums[j]] == 0) {
                    st.erase(nums[j]);
                }
                j++;
            }
        }
        return res;
    }
};