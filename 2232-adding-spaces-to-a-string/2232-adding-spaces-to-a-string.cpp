class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();
        string S(n+m,' ');
        int a = 0;
        for (int i = 0; i < n; i++) {
            if(a<m && i==spaces[a])
            {
                a++;
            }
                S[i+a]=s[i];
            
            
        }
        return S;
    }
};