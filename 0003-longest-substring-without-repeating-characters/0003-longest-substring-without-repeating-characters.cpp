class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int l = 0; // Left pointer of the sliding window
        int maxsize = 0; // To track the maximum size of the substring

        for (int r = 0; r < s.size(); r++) { // Right pointer of the sliding window
            while (set.count(s[r])) { // If character s[r] is already in the set
                set.erase(s[l]); // Remove the character at the left pointer
                l++; // Move the left pointer to the right
            }
            set.insert(s[r]); // Insert the current character into the set
            maxsize = max(maxsize, r - l + 1); // Update maxsize if necessary
        }

        return maxsize;
    }
};
