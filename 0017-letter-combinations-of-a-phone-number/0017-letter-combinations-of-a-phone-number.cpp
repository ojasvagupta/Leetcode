class Solution {
public:
void solve(vector<string>& res,vector<string> v,int n,string s)
{
    if(n==-1)
    {
        res.push_back(s);
        return;
    }
    for(auto a : v[n])
    {
        
        solve(res,v,n-1,s+a);
    }


}
    vector<string> letterCombinations(string digits) {
        if(digits=="")
        {
            return {};
        }
        unordered_map<int,string> mp;
        vector<string> res;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";        
        int a=stoi(digits);
        vector<string> v;
        while(a!=0)
        {
            int x=a%10;
            a=a/10;
            v.push_back(mp[x]);
        }
        int n=v.size();
        string s="";
        solve(res,v,n-1,s);
        return res;
    }
};