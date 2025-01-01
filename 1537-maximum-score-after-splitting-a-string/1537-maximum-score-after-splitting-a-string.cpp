class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int one=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                one++;
            }
        }
        int zero=0;
        int res=-1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0')
           {
                zero++;
           }
           else
           {
            one--;
           }
           res=max(res,(zero+one));
        }
        return res;
        
    }
};