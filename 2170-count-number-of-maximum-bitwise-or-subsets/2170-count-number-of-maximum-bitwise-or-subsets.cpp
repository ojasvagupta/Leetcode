class Solution {
public:
void count(vector<int> nums,int max,int &res,int i,int n)
{
   
    if(max==i)
    {
        res++;
    }
    for(int a=n;a>=0;a-- )
    {
        
        count(nums,max,res,i|nums[a],a-1);
    }
}
    int countMaxOrSubsets(vector<int>& nums) {
        int max=0;
       for(auto num : nums)
       {
        max|=num;
       }
        int res=0;
        count(nums,max,res,0,nums.size()-1);
        return res;
        
    }
};