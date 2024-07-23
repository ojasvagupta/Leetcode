class Solution {
public:
unordered_map<int,int> mp;
    vector<int> frequencySort(vector<int>& nums) {
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(nums[i]))
            {
                mp[nums[i]]++;
            }
            else
            {
                mp[nums[i]]=1;
            }
        }
        sort(nums.begin(),nums.end(),[this](int a,int b)
        {
           if(mp[a]<mp[b])
    {
        return true;
    }
    if(mp[a]==mp[b] && a>b)
    {
            return true;
        
    }
    return false; 
        });
        return nums;
    }
};