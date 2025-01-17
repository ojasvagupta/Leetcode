class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int first;
        int last;
        int n = derived.size();
        if (derived[n - 1] == 0) {
            first = 0;
            last = 0;
        } else {
            first = 1;
            last = 0;
        }
        int second = first;
        for (int i = 0; i < derived.size() - 1; i++) {
            if (derived[i] == 1) {
                second = !first;
            }
            first = second;
        }
        if (second == last) {
            return true;
        }
        return false;
    }
};