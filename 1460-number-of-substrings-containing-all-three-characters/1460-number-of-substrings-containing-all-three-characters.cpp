class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0}; // Count of 'a', 'b', 'c'
        int left = 0, res = 0;
        
        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'a']++; // Increase count for s[right]

            // If we have all three characters, move `left` to minimize the window
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                res += s.size() - right; // All substrings starting from `left`
                count[s[left] - 'a']--; // Remove s[left] from the window
                left++; // Shrink the window
            }
        }
        return res;
    }
};
