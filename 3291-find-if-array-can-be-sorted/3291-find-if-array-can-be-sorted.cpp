class Solution {
public:
    bool setbit(int a, int b) {
        int count1 = 0;
        int count2 = 0;
        while (a) {
            count1 = count1 + (a & 1);
            a >>= 1;
        }
        while (b) {
            count2 = count2 + (b & 1);
            b >>= 1;
        }
        if (count1 == count2) {
            return true;
        }
        return false;
    }
    bool canSortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1] && setbit(nums[i], nums[i + 1])) {
                swap(nums[i], nums[i + 1]);
                for (int j = i; j >= 1; j--) {
                    if (nums[j - 1] > nums[j] && setbit(nums[j], nums[j - 1])) {
                        swap(nums[j], nums[j - 1]);
                    } else if (nums[j - 1] > nums[j] &&
                               !setbit(nums[j], nums[j - 1])) {
                        return false;
                    }
                }
            } else if (nums[i] > nums[i + 1] && !setbit(nums[i], nums[i + 1])) {
                return false;
            }
        }
        return true;
    }
};