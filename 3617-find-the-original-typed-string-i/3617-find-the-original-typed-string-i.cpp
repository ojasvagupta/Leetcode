class Solution {
public:
    int possibleStringCount(string word) {
        if(word.size()==1)
        {
            return 1;
        }
        int res=0;
        int count=0;
        int i=0;
        while(i<word.size())
            {
                if(word[i]==word[i+1])
                {
                    while(word[i]==word[i+1] && i+1<word.size())
                        {
                            count++;
                            i++;
                        }
                    res=res+count;
                }
                count=0;
                i++;
            }
        return res+1;
        
    }
};