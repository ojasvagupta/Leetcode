class Solution {
public:
    bool canFormPairs(vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        for (int i = 1; i < nums.size(); ) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i += 2; // skip both elements (non-overlapping)
            } else {
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums[0];
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFormPairs(nums, p, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return answer;
    }
};
