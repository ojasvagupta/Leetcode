class Solution {
public:
    void create(int open, int close, string s, vector<string>& res) {
        // If no more parentheses to add, add the result
        if (open == 0 && close == 0) {
            res.push_back(s);
            return;
        }
        
        // Add an open parenthesis if available
        if (open > 0) {
            create(open - 1, close, s + "(", res);
        }
        
        // Add a close parenthesis if it can balance an open one
        if (close > open) {
            create(open, close - 1, s + ")", res);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        create(n, n, "", res);  // Start with n open and close parentheses
        return res;
    }
};
