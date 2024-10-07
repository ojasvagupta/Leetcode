class Solution {
public:
    int minLength(string s) {
        bool count=false;
        int i=0;
        while(!count)
        {
            if(s.substr(i,2)=="AB" or s.substr(i,2)=="CD")
            {
                s=s.substr(0,i)+s.substr(i+2);
                i=0;
            }
            else
            {
                i++;
            }
            if(i>s.size())
            {
                count=true;
            }
        }
        return s.size();
        
    }
};