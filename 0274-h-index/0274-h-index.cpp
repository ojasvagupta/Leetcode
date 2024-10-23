class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int res = 0;
        int n = citations.size();
        
        // Iterate through the sorted citations
        for (int i = 0; i < n; i++) {
            int h = n - i;  // Number of papers with at least citations[i] citations
            if (citations[i] >= h) {
                res = h;  // Update the result when the condition is met
                break;    // Once we find the maximum valid H-Index, we can stop
            }
        }
        
        return res;
    }
};
