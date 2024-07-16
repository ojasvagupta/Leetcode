class Solution {
public:

    int fib(int n) {
        static unordered_map<int,int> mp;
        if(mp.count(n)==1)
        {
            return mp[n];
        }
        if(n==0||n==1)
        {
            return n;
        }
         mp[n-1]=fib(n - 1);
         mp[n-2]=fib(n-2);
        return mp[n-1] +mp[n-2];
    }
};