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
            if(mp[nums[i]]>1)
            {
                int a=(i+1)%3;
                if(a>0)
                {
                    return ((i+1)/3)+1;
                }

                return (i+1)/3;
            }
        }
        int res=0;
        return res;
    }
};