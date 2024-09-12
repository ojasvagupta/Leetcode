class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 or nums.size()==1)
        {
            return nums.size();
        }
        unordered_map<int,bool> mp;
        int res=1;
        int maxi=1;
        for(auto a : nums)
        {
            mp[a]=true;
        }
        int i=0;
        int x=0;
        while(i<nums.size())
        {
            if(!mp.count(nums[i]-1))
            {
                int a =nums[i];
                while(mp.count(a+1))
                {
                    res++;
                    a=a+1;
                }
                maxi=max(maxi,res);
                res=1;
            }
            i++;
            
        }
        return maxi;
        
    }
};