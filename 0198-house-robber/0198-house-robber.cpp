class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(nums.size(),0);
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        v[0]=nums[0];
        v[1]=nums[1];
        int maxi=nums[0];
        for(int i=2;i<nums.size();i++)
        {
            v[i]=nums[i]+maxi;
            maxi=max(maxi,v[i-1]);
        }
        return max(v[n-1],v[n-2]);
    }
};