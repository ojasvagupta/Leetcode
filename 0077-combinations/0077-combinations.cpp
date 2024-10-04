class Solution {
public:
    void solve(vector<vector<int>>& res, int n, int k, vector<int> temp,
               int a) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }
        for (int i = n+1; i <= a; i++) {
            temp.push_back(i);
            solve(res, i, k, temp, a);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        
        for (int i = 1; i <= n; i++) {
           vector<int> temp;
            temp.push_back(i);
            solve(res, i, k, temp, n);
        }

        return res;
    }
};