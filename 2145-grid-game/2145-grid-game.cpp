class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long> sum1(n+1,0);
        vector<long long> sum2(n+1,0);
        for(int i=0;i<n;i++)
        {
            sum1[i+1]=sum1[i]+grid[0][i];
            sum2[i+1]=sum2[i]+grid[1][i];
        }
        long long maxi=LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            long long temp=max(sum1[n]-sum1[i+1],sum2[i]);
            maxi=min(maxi,temp);
        }
        return maxi;

    }
};