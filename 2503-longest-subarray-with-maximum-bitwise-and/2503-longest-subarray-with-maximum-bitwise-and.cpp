class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN;
        int count=0;
        int res=0;
        for (auto a : nums) {
            if (a > maxi) {
                maxi = max(maxi, a);
                count=0;
                res=0;
            }
            if (a == maxi) {
                count++;
            } else {
                count = 0;
            }
            res = max(res, count);
           
        }
        return res;
    }
};