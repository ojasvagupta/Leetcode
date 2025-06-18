class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        vector<vector<int>> v;
        while(i<nums.size())
        {
            int count=0;
            vector<int> temp;
            int mini=INT_MAX;
            int maxi=INT_MIN;
            while(count<3)
            {
                mini=min(mini,nums[i+count]);
                maxi=max(maxi,nums[i+count]);
                temp.push_back(nums[i+count]);
                count++;
            }
            if(maxi-mini<=k)
            {
                v.push_back(temp);
                i=i+3;
            }
            else
            {
                return {};
            }
        }
        return v;
    }
};