class Solution {
public:
    bool check(vector<int>& nums) {
        int x=0;
        vector<int> res;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                x=i+1;
                break;
            }
        }
        for(int i=x;i<nums.size();i++)
        {
            res.push_back(nums[i]);
        }
        for(int i=0;i<x;i++)
        {
            res.push_back(nums[i]);
        }
        vector<int> temp=res;
        sort(temp.begin(),temp.end());
        if(temp==res)
        {
            return true;
        }
        return false;
        
    }
};