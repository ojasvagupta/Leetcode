class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count1=1;
        int count2=1;
        int num2;
        int res=0;
        int i=0;
        int num1=nums[0];
        while(i+1<nums.size() && nums[i]==nums[i+1])
        {
            count1++;
            i++;
        }
        while(i+1<nums.size())
        {
            i++;
            num2=nums[i];
            while(i+1<nums.size() && nums[i]==nums[i+1])
            {
                count2++;
                i++;
                
            }
            if(num2-num1==1)
            {
                res=max(res,count1+count2);
            }
            count1=count2;
            num1=num2;
            count2=1;
        }
        return res;
    }
};