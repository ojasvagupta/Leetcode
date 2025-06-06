class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minSuf(n + 1, '{'); // '{' is greater than 'z'
        
        // Build min suffix array
        for (int i = n - 1; i >= 0; --i) {
            minSuf[i] = min(s[i], minSuf[i + 1]);
        }

        string t, p;
        for (int i = 0; i < n; ++i) {
            t.push_back(s[i]);
            while (!t.empty() && t.back() <= minSuf[i + 1]) {
                p.push_back(t.back());
                t.pop_back();
            }
        }

        while (!t.empty()) {
            p.push_back(t.back());
            t.pop_back();
        }

        return p;
    }
};
