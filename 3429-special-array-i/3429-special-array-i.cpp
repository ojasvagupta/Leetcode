class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        } else {
            int rem1 = nums[0] % 2;
            for (int i = 1; i < nums.size(); i++) {
                int rem2 = nums[i] % 2;
                if (rem1 == rem2) {
                    return false;
                }
                rem1 = rem2;
            }
        }
        return true;
    }
};