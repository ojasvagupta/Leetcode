class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {

        vector<int> res;
        for (int i = 0; i < matrix.size(); i++) {
            int temp1 = INT_MAX;
            int temp2 = INT_MIN;
            int check = 0;
            for (int j = 0; j < matrix[i].size(); j++) {
                temp1 = min(temp1, matrix[i][j]);
            }
            for (int j = 0; j < matrix[i].size(); j++) {

                if (temp1 == matrix[i][j]) {
                    check = j;
                }
            }
            for (int j = 0; j < matrix.size(); j++) {
                temp2 = max(temp2, matrix[j][check]);
            }
            if (temp1 == temp2) {
                res.push_back(temp1);
            }
        }
        return res;
    }
};