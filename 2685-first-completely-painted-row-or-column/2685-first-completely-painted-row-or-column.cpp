class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Map to store the position of each value in the matrix
        vector<vector<int>> positions(arr.size() + 1, vector<int>(2));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                positions[mat[i][j]] = {i, j};
            }
        }

        // Arrays to track how many cells are visited in each row and column
        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);

        // Process each element in `arr` and update row/column counts
        for (int i = 0; i < arr.size(); ++i) {
            int value = arr[i];
            int row = positions[value][0];
            int col = positions[value][1];

            // Increment visit counts for the corresponding row and column
            rowCount[row]++;
            colCount[col]++;

            // Check if the row or column is fully visited
            if (rowCount[row] == cols || colCount[col] == rows) {
                return i; // Return the index where the first completion happens
            }
        }

        return -1; // If no row or column is completed
    }
};
