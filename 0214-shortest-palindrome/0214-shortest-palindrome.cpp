class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;

        // Create the reverse of the string s
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        // Concatenate original string and reversed string with a separator
        string combined = s + "#" + rev;
        
        // KMP table to store the length of the longest prefix which is also a suffix
        vector<int> kmp(combined.size(), 0);
        
        for (int i = 1; i < combined.size(); i++) {
            int j = kmp[i - 1];
            
            while (j > 0 && combined[i] != combined[j]) {
                j = kmp[j - 1];
            }
            
            if (combined[i] == combined[j]) {
                j++;
            }
            
            kmp[i] = j;
        }
        
        // The length of the longest palindromic prefix
        int longest_palindrome_prefix_len = kmp.back();
        
        // Add the non-palindrome part of the reversed string in front of the original string
        return rev.substr(0, s.size() - longest_palindrome_prefix_len) + s;
    }
};
