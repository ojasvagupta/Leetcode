class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> v(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(mp.count(nums[i]))
            {
                mp[nums[i]]++;
            }
            else
            {
                mp[nums[i]]=1;
            }
            v[i]=mp[nums[i]];
        }
        int count=0;
        int res=0;
        for(int i=0;i<nums.size();i=i+3)
        {
            count++;
            for(int j=i;j<i+3;j++)
            {
                if(j<nums.size() && v[j]>1)
                {
                    res=count;
                    break;
                }
            }
        }
        return res;
    }
};