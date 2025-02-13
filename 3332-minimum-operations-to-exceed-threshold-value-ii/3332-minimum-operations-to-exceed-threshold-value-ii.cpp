class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        while (pq.size() > 1 && pq.top() < k) {
            res++;
            long long t1 = pq.top();
            pq.pop();
            long long t2 = pq.top();
            pq.pop();
            long long t3 = min(t1, t2) * 2 + max(t1, t2);
            pq.push(t3);
        }
        return res;
    }
};