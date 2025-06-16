class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int i=1;
        int a=nums[0];
        int b=nums[0];
        int res=-1;
        while(i<nums.size())
        {
            if(nums[i]<a)
            {
                a=nums[i];
                b=nums[i];
            }
            if(nums[i]>b)
            {
                b=nums[i];
                res=max(res,b-a);
            }
            i++;
        }
        return res;
    }
};