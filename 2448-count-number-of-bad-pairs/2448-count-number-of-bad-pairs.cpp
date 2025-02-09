class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res=0;
        long long count=1;
        unordered_map<int,int> mp;
        nums[0]=-nums[0];
        mp[nums[0]]=1;
        for(int i=1;i<nums.size();i++)
        {
            nums[i]=i-nums[i];
            if(!mp.count(nums[i]))
            {
                mp[nums[i]]=1;
                res=res+count;
                count++;
            }
            else
            {
                res=res+count-mp[nums[i]];
                count++;
                mp[nums[i]]++;
            }
        }
        return res;

    }
};