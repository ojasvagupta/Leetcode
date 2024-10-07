class Solution {
public:
    int minLength(string s) {
        int n=s.length(); 
        stack<char>st; 
        for(auto i:s){ 
            if(st.empty()) st.push(i);
            else{
            if(st.top()=='A' and i=='B'){ 
                st.pop();
            }
            else if(st.top()=='C' and i=='D'){ 
                st.pop();
            }
            else st.push(i);
            }

        } 
        return st.size();
    }
};