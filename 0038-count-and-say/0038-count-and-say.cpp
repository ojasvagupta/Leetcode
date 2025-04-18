class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }
        string s="1";
        for(int i=1;i<n;i++)
        {
            string t="";
            int j=0;
            int count=1;
            while(j<s.size())
            {
                if(j+1<s.size() && s[j]==s[j+1])
                {
                    count++;
                    j++;
                }
                else
                {
                    t=t+to_string(count)+s[j];
                    count=1;
                    j++;
                }
            }
            s=t;
        }
        return s;
    }
};