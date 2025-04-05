class Solution {
public:
void recur(vector<int>& nums,int a,int j,int & res)
{
    res=res+j;
    for(int i=a+1;i<nums.size();i++)
    {
        recur(nums,i,j^nums[i],res);
    }
}
    int subsetXORSum(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            recur(nums,i,nums[i],res);
        }
        return res;
    }
};