class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s; // No zigzag needed
        }

        vector<string> rows(min(numRows, int(s.size())));
        int currRow = 0; // Current row index
        bool goingDown = false; // Direction flag

        // Traverse the input string
        for (char c : s) {
            rows[currRow] += c; // Add the character to the current row
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown; // Change direction at boundaries
            }
            currRow += goingDown ? 1 : -1;
        }

        // Combine all rows to form the result
        string result;
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};
