class Solution {
    struct cmp {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        vector<char> v(s.size(), '/');
        for (int i = 0; i < s.size(); i++) {
            if(s[i]!='*')
            {
                v[i]=s[i];
                pq.push({s[i],i});
            }
            else
            {
              v[i]='/';
              int b = pq.top().second;
              pq.pop();
              v[b]='/';
            }
           
        }
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (v[i] != '/') {
                res += v[i];
            }
        }
        return res;
    }
};