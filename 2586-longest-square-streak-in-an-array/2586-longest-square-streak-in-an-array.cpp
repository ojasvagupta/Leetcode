class Solution {
public:
    bool search(vector<int>& nums, int start, int end, long long num, int& set) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == num) {
                set = mid;
                return true;
            }
            if (nums[mid] > num) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }

    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int answer = 1;

        for (int i = 0; i < nums.size(); i++) {
            int count = 1;
            long long check =1LL* nums[i] * nums[i];
            int mid = 0;

            // Early exit if it's impossible to find a longer streak
            if (answer > nums.size() - i - 1) {
               break;
            }

            // Look for the square streak
            while (search(nums, i + 1, nums.size() - 1, check, mid)) {
                count++;
                check =1LL* nums[mid] * nums[mid]; // Next square to search
            }
            answer = max(answer, count);
        }
        if (answer == 1) {
            return -1;
        }
        return answer;
    }
};
