class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.length();
        int m=part.length();
        int i=0;
        int a=INT_MAX;
        while(i<s.length())
        {
            if(s[i]==part[0])
            {
                if(i<a)
                {
                    a=i;
                }
                if(s.substr(i,m)==part)
                {
                    s.erase(i,m);
                    i=a;    
                }
                else
                {
                    i++;
                }
            }
            else
            {
                i++;
            }
            
        }
        return s;
    }
};