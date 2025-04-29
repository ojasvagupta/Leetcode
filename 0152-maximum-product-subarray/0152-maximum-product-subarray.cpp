class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmin=nums[0];
        int currmax=nums[0];
        int maxprod=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int temp=max({nums[i],currmin*nums[i],currmax*nums[i]});
            currmin=min({nums[i],currmin*nums[i],currmax*nums[i]});
            currmax=temp;
            maxprod=max(maxprod,currmax);
        }
        return maxprod;
    }
};