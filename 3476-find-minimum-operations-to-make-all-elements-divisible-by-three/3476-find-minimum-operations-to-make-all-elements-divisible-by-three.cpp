class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        if(n==0)
        {
            return count;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]%3==1)
            {
                nums[i]=nums[i]-1;
                count++;
                
            }
            else if(nums[i]%3==2)
            {
                nums[i]=nums[i]+1;
                count++;
            }
        }
        return count;
        
    }
};