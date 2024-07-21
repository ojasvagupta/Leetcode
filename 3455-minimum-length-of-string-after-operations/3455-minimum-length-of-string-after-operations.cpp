class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.count(s[i]))
            {
                mp[s[i]]++;
            }
            else
            {
                mp[s[i]]=1;
            }
        }
        int len=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if((it->second)>2)
            {
                if(it->second%2==0)
                {
                len=len + it->second - 2;
                }
                else
                {
                    len=len+it->second-1;
                }
            }
        }
        return s.size()-len;

    }
};