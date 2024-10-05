class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        if (n1 > n2) return false; // If s1 is longer than s2, return false
        
        // Frequency arrays for s1 and the sliding window in s2
        vector<int> v1(26, 0), v2(26, 0);
        
        // Populate the frequency array for s1 and the first window in s2
        for (int i = 0; i < n1; ++i) {
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        
        // Now slide the window over s2, from index n1 to n2
        for (int i = n1; i < n2; ++i) {
            // Check if the frequency matches at each step
            if (v1 == v2) return true;
            
            // Slide the window: include s2[i] and exclude s2[i - n1]
            v2[s2[i] - 'a']++;      // Add the new character to the window
            v2[s2[i - n1] - 'a']--; // Remove the character that's left out of the window
        }
        
        // Check the last window
        return v1 == v2;
    }
};
