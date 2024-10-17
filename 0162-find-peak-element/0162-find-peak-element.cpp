class Solution {
public:
void find(int end,int start,int& i,vector<int> nums)
{
    int mid=(end+start)/2;
    if(mid<0 or mid>=nums.size() or i!=-1)
    {
        return;
    }
    if(mid==0 && nums[mid]>nums[mid+1])
    {
        i=mid;
        return;
    }
    if(mid==nums.size()-1 && nums[mid]>nums[mid-1])
    {
        i=mid;
        return;
    }
    if(nums[mid]>nums[mid+1] && nums[mid-1]<nums[mid])
    {
        i=mid;
        return;
    }
    if (mid > 0 && nums[mid - 1] > nums[mid]) {
            find(start, mid - 1, i, nums);
        }
        else {
            find(mid + 1, end, i, nums);
        }
}
    int findPeakElement(vector<int>& nums) {
        if( nums.size()==1)
        {
            return 0;
        }
        int end=nums.size()-1;
        int start=0;
        int i=-1;
        find(end,start,i,nums);
        return i;
        
    }
};