class Solution {
public:
    string makeFancyString(string s) {
        if (s.empty()) return ""; 
        string ans;
        ans.reserve(s.size()); 
        int count = 1;  
        ans += s[0];  
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;  
            }

            if (count < 3) {
                ans += s[i];
            }
        }

        return ans;
    }
};