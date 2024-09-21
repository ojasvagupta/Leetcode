class Solution {
public:
void calc(int n,vector<int>& res,int num)
{
    if(num<=n && num/10!=0)
    {
        res.push_back(num);
    }
    if(num>n)
    {
        return;
    }
    for(int x=0;x<=9;x++)
    {
        
        int nextnum=num*10+x;
        calc(n,res,nextnum);
    }

}
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1;i<=9;i++)
        {
            if(i<=n)
            {
                res.push_back(i);
            }
            calc(n,res,i);
        }
        return res;

        
    }
};