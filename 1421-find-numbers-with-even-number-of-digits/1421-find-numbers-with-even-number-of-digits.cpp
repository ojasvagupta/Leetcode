class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            int n=nums[i];
            int cnt=0;
            while(n>0)
            {
                cnt++;
                n=n/10;
            }
            if(cnt%2==0)
            {
                res++;
            }
        }
        return res;
    }
};