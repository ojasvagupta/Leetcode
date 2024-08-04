class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        int lft=0;
        while(lft<n)
        {
            int rght=lft;
            while(rght<n)
            {
                int sum=0;
                for(int i=lft;i<rght+1;i++)
                {
                    sum=sum+nums[i];
                }
                v.push_back(sum);
                rght++;
            }
            lft++;
        }
        sort(v.begin(),v.end());
        long long int res=0;
        for(int i=left-1;i<right;i++)
        {
            res=res+v[i];
        }
        res=res%1000000007;
        return res;

        
    }
};