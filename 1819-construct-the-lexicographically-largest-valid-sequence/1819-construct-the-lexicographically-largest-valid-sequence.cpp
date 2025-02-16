class Solution {
public:
    void clc(int n, vector<int>& v, vector<int>& pre, vector<int>& res,
             unordered_set<int>& st, bool& check, int idx) {
        if (check)
            return; // Stop when a valid sequence is found

        if (idx == v.size()) { // All positions filled
            res = v;
            check = true;
            return;
        }

        if (v[idx] != -1) { // Skip already filled positions
            clc(n, v, pre, res, st, check, idx + 1);
            return;
        }

        for (int num : pre) {
            if (st.count(num))
                continue; // Skip already placed numbers

            st.insert(num);
            v[idx] = num;

            if (num > 1 && idx + num < v.size() && v[idx + num] == -1) {
                v[idx + num] = num;
                clc(n, v, pre, res, st, check, idx + 1);
                if (check)
                    return;        // Stop if sequence found
                v[idx + num] = -1; // Backtrack
            } else if (num ==
                       1) { // '1' appears only once, no second position needed
                clc(n, v, pre, res, st, check, idx + 1);
                if (check)
                    return;
            }

            v[idx] = -1; // Backtrack
            st.erase(num);
        }
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> pre;
        for (int i = n; i >= 1; i--)
            pre.push_back(i);

        vector<int> v((2 * n) - 1, -1); // Correct size of sequence
        vector<int> res;
        bool check = false;
        unordered_set<int> st;

        clc(n, v, pre, res, st, check, 0);
        return res;
    }
};
