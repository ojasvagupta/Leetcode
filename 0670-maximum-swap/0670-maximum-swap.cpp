class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        bool sp = false;
        int i = 0;
        int j = 0;
        while (!sp && j < s.size()) {
            stack<pair<char, int>> st;
            st.push({s[i], i});
            while (i < s.size()) {
                auto x = st.top();
                if (s[i] >= x.first) {
                    st.push({s[i], i});
                }
                i++;
            }
            auto x = st.top();
            if (x.first == s[j]) {
                while (s[j] == x.first) {
                    j++;
                }
            } else if (x.first > s[j]) {
                swap(s[x.second], s[j]);
                sp = true;
            }
            i = j;
        }
        int res = stoi(s);
        return res;
    }
};