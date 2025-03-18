class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left=0;
        int right=1;
        int temp=nums[0];
        int count=1;
        int res=1;
        while(right<nums.size())
        {
           int i=right-1;
           while(i>=left)
           {
            if((nums[right]&nums[i])!=0)
            {
                left=i+1;
                break;
            }
            i--;
           }
           count=right-left+1;
           res=max(count,res);
           right++;
        }
        return res;
    }
};