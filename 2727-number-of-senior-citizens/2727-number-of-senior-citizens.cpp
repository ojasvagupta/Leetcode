class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (auto a : details) {
            string b = "";
            char c = a[11];
            char d = a[12];
            b = c;
            b = b + d;
            int age = stoi(b);
            if (age > 60) {
                res++;
            }
        }
        return res;
    }
};