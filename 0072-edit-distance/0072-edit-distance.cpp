class Solution {
public:
    int helper(string& word1, string& word2, int i, int j, vector<vector<int>>& memo) {
        // Base cases
        if (i == word1.size()) return word2.size() - j; // Remaining characters to insert
        if (j == word2.size()) return word1.size() - i; // Remaining characters to delete

        // Check memo table
        if (memo[i][j] != -1) return memo[i][j];

        // If characters match, move to the next pair
        if (word1[i] == word2[j]) {
            return memo[i][j] = helper(word1, word2, i + 1, j + 1, memo);
        }

        // Otherwise, calculate the minimum of the three possible operations:
        // Insert, Delete, Replace
        int insertOp = helper(word1, word2, i, j + 1, memo);      // Insert
        int deleteOp = helper(word1, word2, i + 1, j, memo);      // Delete
        int replaceOp = helper(word1, word2, i + 1, j + 1, memo); // Replace

        // Store the result in memo and return
        return memo[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        // Create a memo table and initialize it with -1
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        // Start recursion from the first characters of both strings
        return helper(word1, word2, 0, 0, memo);
    }
};
