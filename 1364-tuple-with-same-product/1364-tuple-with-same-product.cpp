class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int product=nums[i]*nums[j];
                if(mp.count(product))
                {
                    mp[product]++;
                }
                else
                {
                    mp[product]=1;
                }
            }
        }
        for(auto i=mp.begin(); i!=mp.end();i++)
        {
            int m=i->second;
            if(m>=2)
            {
                res=res+((m*(m-1))/2)*8;
            }
        }
        return res;
    }
};