class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n=path.size(),i=0;
        while(i<n){
            string s="";
            if(path[i]=='/'){
                i++;
                continue;
            }
            else{
                while(i<n && path[i]!='/'){
                    s+=path[i];
                    i++;
                }
                if(s==".") continue;
                else if(s==".."){ if(!st.empty()) st.pop();}
                else
                st.push(s);
            }

        }
        string ans="";
        if(st.empty()) {
            ans+="/";
            return ans;
        }
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }
        return ans;

    }
};