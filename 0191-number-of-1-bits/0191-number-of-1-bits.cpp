class Solution {
public:
    int hammingWeight(int n) {
        string res="";
        long long i=1;
        while(n>0)
        {
            string mod=to_string(n%2);
            n=n/2;
            res=mod+res; 
        }
        int count=0;
        for(int i=0;i<res.size();i++)
        {
            if(res[i]=='1')
            {
                count++;
            }
        }
        return count;
    }
};