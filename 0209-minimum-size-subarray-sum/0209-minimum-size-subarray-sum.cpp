class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n=nums.size();
       int sum=0;
       int l=0;
       int r=1;
       int minl=INT_MAX;
       for(int i=0;i<n;i++)
       {
        sum=sum+nums[i];
        
       }
       if(sum<target)
       {
        return 0;
       }
       sum=nums[0];
       
       while(l<=r)
       {
         if(sum<target && r<n)
         {
            sum=sum+nums[r];
            r++;
         }
         else
         {
            if(sum>=target){
            int len=r-l;
            minl=min(minl,len);
            sum=sum-nums[l];
            }
            l++;
            
         }
       }
       
       return minl;
       
    }
};