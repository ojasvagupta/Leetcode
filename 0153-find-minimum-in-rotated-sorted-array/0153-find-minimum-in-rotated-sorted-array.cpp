class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        if(nums[start]<nums[end])
        {
            return nums[start];
        }
        int mid=(end+start)/2;
        while(end>=start)
        {
             mid=(end+start)/2;
            if(mid+1<nums.size() && mid-1>=0 && nums[mid+1]>nums[mid] && nums[mid-1]>nums[mid])
            {
                return nums[mid];
            }
            if(mid+1<nums.size() && mid-1>=0 && nums[mid+1]<nums[mid] && nums[mid-1]<nums[mid])
            {
                return nums[mid+1];
            }
            if(nums[mid]>=nums[0])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return nums[mid];

    }
};