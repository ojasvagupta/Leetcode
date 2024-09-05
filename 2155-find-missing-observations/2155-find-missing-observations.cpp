class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> v(n,1);
        int sum1=0;
        for(int i=0;i<rolls.size();i++)
        {
            sum1=sum1+rolls[i];
        }
        int sum2=mean*(rolls.size()+n)-sum1;
        if(sum2 < n || sum2 > 6 * n) {
            return {}; 
        }
        int diff=sum2-n;
        int c=0;
        while(diff>0)
        {
           if(c==n)
           {
            c=0;
           }
           v[c]++;
            diff--;
            c++;
        }
        
        return v;
        
    }
};