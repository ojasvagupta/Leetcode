class Solution {
public:
    static bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second; // sort by index
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Min-heap of (value, index) to keep k largest values
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
            if (pq.size() > k) pq.pop();  // Maintain top-k largest values
        }

        vector<pair<int, int>> v;
        while (!pq.empty()) {
            v.push_back(pq.top());
            pq.pop();
        }

        // Sort by index to preserve original order
        sort(v.begin(), v.end(), cmp);

        vector<int> res;
        for (auto& p : v)
            res.push_back(p.first);

        return res;
    }
};
