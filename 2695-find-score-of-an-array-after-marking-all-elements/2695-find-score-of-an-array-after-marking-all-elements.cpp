class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        
        // Priority queue to process elements by value in ascending order
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        
        vector<bool> marked(n, false); // Track if an element is already "processed"
        
        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            
            // Skip if this element has been marked
            if (marked[idx]) continue;
            
            // Add value to the score
            score += val;
            
            // Mark current index and its neighbors
            marked[idx] = true;
            if (idx > 0) marked[idx - 1] = true;
            if (idx < n - 1) marked[idx + 1] = true;
        }
        
        return score;
    }
};
