class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0;
        
        // Iterate over all 32 possible bit positions
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;
            
            // Count how many numbers have this bit set to 1
            for (int num : candidates) {
                if (num & (1 << bit)) {
                    count++;
                }
            }
            
            // The result is the maximum count for any bit position
            res = max(res, count);
        }
        
        return res;
    }
};
