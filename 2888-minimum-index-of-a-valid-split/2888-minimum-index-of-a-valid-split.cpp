class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mp;
        int dom=INT_MIN;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(nums[i]))
            {
                mp[nums[i]]++;
                if(mp[nums[i]]>count)
                {
                    count=mp[nums[i]];
                    dom=nums[i];
                }
            }
            else
            {
                mp[nums[i]]=1;
            }
        }
        count=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==dom)
            {
                count++;
                if(count>(i+1)/2 && mp[nums[i]]-count>(n-i-1)/2)
                {
                    return i;
                }

            }
        }
        return -1;
    }
};