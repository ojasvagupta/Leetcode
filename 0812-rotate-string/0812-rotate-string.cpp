class Solution {
public:
    bool rotateString(string s, string goal) {
        int x;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == goal[0]) {
                x = i;
                string res = "";
                res = s.substr(x, s.size() - x) + s.substr(0, x);
                if (res == goal) {
                    return true;
                }
            }
        }

        return false;
    }
};