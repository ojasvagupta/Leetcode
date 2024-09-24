class Solution {
public:
    // A helper function to check word break with memoization
    bool solve(const string& s, unordered_set<string>& wordSet, int start, unordered_map<int, bool>& memo) {
        if (start == s.size()) {
            return true;  // If we have successfully segmented the entire string
        }
        
        if (memo.find(start) != memo.end()) {
            return memo[start];  // Return the cached result if already computed
        }

        for (int end = start + 1; end <= s.size(); ++end) {
            if (wordSet.count(s.substr(start, end - start)) && solve(s, wordSet, end, memo)) {
                return memo[start] = true;  // Found a valid segmentation
            }
        }

        return memo[start] = false;  // No valid segmentation found
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> memo;
        return solve(s, wordSet, 0, memo);  // Start checking from index 0
    }
};
