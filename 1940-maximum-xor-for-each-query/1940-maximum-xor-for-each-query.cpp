class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> res;
        int maxVal = (1 << maximumBit) - 1;
        int num=0;
        for(int i=0;i<nums.size();i++)
        {
            num=num^nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            int temp1=0;
            res.push_back(num^maxVal);
            num=num^nums[i];
        }
        return res;
    }
};