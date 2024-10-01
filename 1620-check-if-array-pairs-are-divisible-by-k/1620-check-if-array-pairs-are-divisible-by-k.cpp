class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainder_count(k, 0);
        
        // Count the occurrences of each remainder
        for (int num : arr) {
            int remainder = ((num % k) + k) % k;  // Handle negative numbers
            remainder_count[remainder]++;
        }
        
        // Check if remainders can form pairs
        if (remainder_count[0] % 2 != 0) {
            return false;  // Remainder 0 should be paired within itself
        }
        
        for (int i = 1; i < k; i++) {
            if (remainder_count[i] != remainder_count[k - i]) {
                return false;  // Remainder i must pair with remainder k-i
            }
        }
        
        return true;
    }
};
