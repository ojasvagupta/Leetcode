class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0;
        int j=2;
        int count=0;
        while(j<nums.size())
            {
                int mid=(i+j)/2;
                if(nums[mid]/2.0==nums[i]+nums[j])
                {
                    count++;
                }
                i++;
                j++;
            }
        return count;
    }
};