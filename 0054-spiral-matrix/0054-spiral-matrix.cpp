class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int n = matrix.size();
        int m = matrix[0].size();
        int a = 0;
        int b = n - 1;
        int c = 0;
        int d = m - 1;
        while (a <= b && c <= d) {
            for (int i = c; i <= d; i++) {
                v.push_back(matrix[a][i]);
            }
            a++;
            for (int i = a; i <= b; i++) {
                v.push_back(matrix[i][d]);
            }
            d--;
            if (a <= b) {
                for (int i = d; i >= c; i--) {
                    v.push_back(matrix[b][i]);
                }
                b--;
            }
            if (c <= d) {
                for (int i = b; i >= a; i--) {
                    v.push_back(matrix[i][c]);
                }
                c++;
            }
        }

        return v;
    }
};