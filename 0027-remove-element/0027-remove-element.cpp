class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        vector<int> v;
        int k=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=val)
            {
                v.push_back(nums[i]);
                k=k+1;
            }
            
        }
        nums=v;
        return (k);
        
    }
};