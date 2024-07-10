class Solution {
public:
    int minOperations(vector<string>& logs) {
        int st=0;
        for (auto a : logs) {
            if (a == "../" && st!=0) {
                st--;
            } else if (a == "./") {
                continue;
            } else if (a != "./" && a != "../") {
                st++;
            }
        }
        return st;
    }
};