class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,bool> mp;
        int res=0;
        for(auto a : allowed)
        {
            mp[a]=true;
        }
        for(auto a : words)
        {
            int x=1;
            for(auto b : a)
            {
                
                if(!mp.count(b))
                {
                    x=0;
                    break;
                }
            }
            res=res+x;
        }
        return res;
        
    }
};