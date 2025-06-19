class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // Build a min-heap
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());

        int count = 0;

        while (!minHeap.empty()) {
            int minVal = minHeap.top();  // start a new group
            minHeap.pop();

            // Remove all elements that can fit into the current group (minVal to minVal + k)
            while (!minHeap.empty() && minHeap.top() - minVal <= k) {
                minHeap.pop();
            }

            count++;
        }

        return count;
    }
};
