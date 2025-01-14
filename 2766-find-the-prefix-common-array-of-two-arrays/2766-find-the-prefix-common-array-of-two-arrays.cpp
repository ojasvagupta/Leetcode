class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> a;
        unordered_set<int> b;
        int n = A.size();
        int count=0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            a.insert(A[i]);
            b.insert(B[i]);
            if (B[i] == A[i]) {
                count++;
            } else {
                if (b.count(A[i])) {
                    count++;
                }
                if (a.count(B[i])) {
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};