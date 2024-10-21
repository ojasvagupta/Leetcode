class Solution {
public:
    void sol(string s, int j, unordered_set<string> st, int count,
             int& res) {

        if (j >= s.size() ) {
            res = max(res,count);
            return;
        }
        for (int i = 1; i <= s.size()-j; i++) {
           
                string x = s.substr(j, i);
                if (!st.count(x)) {
                    st.insert(x);
                    sol(s, j + i,st, count+1, res);
                    st.erase(x);
                }
                
                
            
        }
    }
    int maxUniqueSplit(string s) {
        string x = "";
        int count = 0;
        unordered_set<string> st;
        sol(s, 0, st, 0, count);
        return count;
    }
};