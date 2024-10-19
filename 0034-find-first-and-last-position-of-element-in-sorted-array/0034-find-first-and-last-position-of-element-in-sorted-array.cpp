class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int s = -1;
        int e = -1;
        while (end >= start) {
            int mid = (end + start) / 2;
            if (nums[mid] == target) {
                s = mid;
                e = mid;

                while (s >= 0 && nums[s] == target) {
                    s--;
                }
                while (e < nums.size() && nums[e] == target) {
                    e++;
                }
                return {s+1,e-1};
            }
            if (nums[mid] < target) {
                start = mid + 1;
            }
            if (nums[mid] > target) {
                end = mid - 1;
            }
        }
        return {s, e};
    }
};