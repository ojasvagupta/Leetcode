class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int i=0;
        vector<int> v;
        int count=0;
        while(i<n)
        {
            if(s1[i]!=s2[i])
            {
                
                v.push_back(i);
                count++;
                if(count>2)
                {
                    return false;
                }
            }
            
                i++;
            
        }
        if(count==0)
        {
            return true;
        }
        if(v.size()==2 && s1[v[0]]==s2[v[1]] && s1[v[1]]==s2[v[0]])
        {
            return true;
        }
        return false;


    }
};