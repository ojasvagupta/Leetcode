class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();          // Number of rows
        int n = matrix[0].size();       // Number of columns
        
        // Edge case: Empty matrix
        if (m == 0 || n == 0) return false;

        int s = 0, e = m - 1;

        // Binary search to find the potential row
        while (e >= s) {
            int mid = (s + e) / 2;
            if (matrix[mid][0] <= target && matrix[mid][n - 1] >= target) {
                // Binary search in the row 'mid'
                int start = 0, end = n - 1;
                while (start <= end) {
                    int mid1 = (start + end) / 2;
                    if (matrix[mid][mid1] == target) {
                        return true;
                    } else if (matrix[mid][mid1] > target) {
                        end = mid1 - 1;
                    } else {
                        start = mid1 + 1;
                    }
                }
                return false;  // Target not found in the row
            }
            if (matrix[mid][0] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return false;  // Target not found in the matrix
    }
};
