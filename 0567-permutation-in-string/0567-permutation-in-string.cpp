class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> v1(26,0);
        
        for(int i=0;i<n1;i++)
        {
            v1[s1[i]-'a']++;
        }
        for(int i=0;i<n2;i++)
        {
            if(v1[s2[i]-'a']>0)
            {
                bool check=true;
                vector<int> v2(26,0);
                int count=0;
                int x=i;
                while(count<n1 && x<n2)
                {
                    v2[s2[x]-'a']++;
                    count++;
                    x++;
                }
                
                for(int j=0;j<n1;j++)
                {
                    if(v1[s1[j]-'a']!=v2[s1[j]-'a'])
                    {
                      check=false;   
                    }
                }
                if(check==true)
            {
                return true;
            }
            }
            
        }
        return false;
    }
};