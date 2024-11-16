class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < k; i++) {
            while (!dq.empty() && (nums[dq.back()] >= nums[i] || nums[i] - nums[dq.back()] > 1)) {
                dq.pop_front();
            }
            dq.push_back(i);
        }

        if (dq.size() == k) {
            ans.push_back(nums[dq.back()]);
        } else {
            ans.push_back(-1);
        }

        for (int i = k; i < nums.size(); i++) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && (nums[dq.back()] >= nums[i] || nums[i] - nums[dq.back()] > 1)) {
                dq.pop_front();
            }
            dq.push_back(i);
            
            if (dq.size() == k) {
                ans.push_back(nums[dq.back()]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};