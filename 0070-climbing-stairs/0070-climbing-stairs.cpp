class Solution {
public:
int calc(int n,int i,vector<int>& v)
{
    if(i==n)
    {
        return 1;
    }
    if(i>n)
    {
        return 0;
    }
    if(v[i]!=0)
    {
        return v[i];
    }
    
    v[i]=calc(n,i+1,v) + calc(n,i+2,v);
    return v[i];
}




    int climbStairs(int n) {
        vector<int> v(n+1,0);
        int i=0;
        return calc(n,i,v);
        
    }
};