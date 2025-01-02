class Solution {
public:
bool isavowel(char x)
{
    if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u')
    {
        return true;
    }
    return false;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> v(words.size()+1,0);
        vector<int> res(queries.size(),0);
        for(int i=1;i<=words.size();i++)
        {
            string s=words[i-1];
            if(isavowel(s[0]) && isavowel(s[s.size()-1]))
            {
                v[i]=v[i-1]+1;
            }
            else
            {
                v[i]=v[i-1];
            }
        }
        for(int i=0;i<queries.size();i++)
        {
            int a=queries[i][0];
            int b=queries[i][1]+1;
            res[i]=v[b]-v[a];
        }
        return res;
        
    }
};