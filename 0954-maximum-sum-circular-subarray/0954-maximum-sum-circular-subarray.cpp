class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int localmax=0;
        int globalmax=INT_MIN;
        int localmin=0;
        int globalmin=INT_MAX;
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++)
        {
            totalsum=totalsum+nums[i];
            localmax=max(localmax+nums[i],nums[i]);
            globalmax=max(localmax,globalmax);
            localmin=min(localmin+nums[i],nums[i]);
            globalmin=min(localmin,globalmin);

           
        }
         if(globalmax<0)
            {
                return globalmax;
            }
        return max(globalmax,totalsum-globalmin);
    }
};