class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];
            if (c == '!' or c == '&' or c == '|') {
                st.push(c);
            }
            if (c == 't') {
                st.push(c);
            }
            if (c == 'f') {
                st.push(c);
            }
            if (c == ')') {
                int t = 0;
                int f = 0;
                while (st.top() == 't' || st.top() == 'f') {
                    if (st.top() == 't') t++;
                    else f++;
                    st.pop();
                }
                if (st.top() == '|') {
                    st.pop();
                    if (t > 0) {
                        st.push('t');
                    } else {
                        st.push('f');
                    }
                } else if (st.top() == '&') {
                    st.pop();
                    if (f > 0) {
                        st.push('f');
                    } else {
                        st.push('t');
                    }
                } else if (st.top() == '!') {
                    st.pop();
                    if (t>0) {
                        st.push('f');
                    } else {
                        st.push('t');
                    }
                }
            }
        }
        if (st.top() == 't') {
            return true;
        }
        return false;
    }
};