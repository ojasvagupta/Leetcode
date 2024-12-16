class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // Custom comparator for priority_queue
        auto comparator = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first; // Min-heap based on the first element
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(comparator)>
            pq(comparator);

        // Push the first k elements into the priority queue
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        // Process the priority queue for k iterations
        for (int i = 0; i < k; i++) {
            auto [a, b] = pq.top();
            pq.pop();
            a = a * multiplier;
            nums[b] = nums[b] * multiplier;
            pq.push({a, b});
        }

        return nums;
    }
};
