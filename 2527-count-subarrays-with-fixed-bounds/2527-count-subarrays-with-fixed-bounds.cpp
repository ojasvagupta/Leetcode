class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int imin=0;
        int imax=0;
        int mini=INT_MIN;
        int maxi=INT_MAX;
        long long res=0;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mini<minK or maxi>maxK)
            {
                mini=nums[i];
                maxi=nums[i];
                j=i;
            }
            if(nums[i]<=mini)
            {
                mini=nums[i];
                imin=i;
            }
            if(nums[i]>=maxi)
            {
                maxi=nums[i];
                imax=i;
            }
            if(mini==minK && maxi==maxK)
            {
                res=res+min(imin,imax)-j+1;
            }
        }
        return res;
    }
};