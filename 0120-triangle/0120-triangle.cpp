class Solution {
public:
    void count(vector<vector<int>>& triangle, int i, int j, int sum, int& res,
               vector<vector<int>>& memo) {
        if (j >= triangle.size()) {
            res = min(res, sum);
            return;
        }
        if (i >= triangle[j].size()) return;


        sum = sum + triangle[j][i];
       
        if (sum >= memo[j][i]) {
            
            return;
        }
         memo[j][i] = sum;
        count(triangle, i, j + 1, sum, res, memo);
        count(triangle, i + 1, j + 1, sum, res, memo);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> memo;
        for (int i = 0; i < triangle.size(); i++) {
            vector<int> v(triangle[i].size(), INT_MAX);
            memo.push_back(v);
        }
        int res = INT_MAX;
        count(triangle, 0, 0, 0, res, memo);
        return res;
    }
};