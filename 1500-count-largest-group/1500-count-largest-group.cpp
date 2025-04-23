class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> v(37,0);
        for(int i=1;i<=n;i++)
        {
            int x=i;
            int sum=0;
            while(x!=0)
            {
                sum=sum+x%10;
                x=x/10;
            }
            v[sum]++;
        }
        sort(v.begin(),v.end(),greater<int>());
        int a=v[0];
        int i=1;
        int count=1;
        while(a==v[i])
        {
            count++;
            i++;
        }
        return count;
    }
};