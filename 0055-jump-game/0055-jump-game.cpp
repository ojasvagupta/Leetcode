class Solution {
public:
    bool canJump(vector<int>& nums) {
        int a=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>a)
            {
                return false;
            }
            a=max(a,i+nums[i]);
            if(a>=nums.size()-1)
            {
                return true;
            }

        }
        return false;
    }
};