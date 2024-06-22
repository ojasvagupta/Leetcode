class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < (nums.size() - 2); i++) {
            if (nums[i] == 0) {
                for (int j = i; j < (i + 3); j++) {
                    if (nums[j] == 0) {
                        nums[j] = 1;
                    } else if (nums[j] == 1) {
                        nums[j] = 0;
                    }
                }
                count++;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count = count;
            } else {
                count = -1;
                break;
            }
        }
        return count;
    }
};