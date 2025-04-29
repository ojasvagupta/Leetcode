class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);
        }
        int i=0;
        int j=0;
        int count=0;
        long long res=0;
        while(j<nums.size())
        {
            if(nums[j]==maxi)
            {
                count++;
            }
            while(count>=k)
            {
                res=res+(nums.size()-j);
                if(nums[i]==maxi)
                {
                    count--;
                }
                i++;
            }
            j++;
        }
        return res;
        
    }
};