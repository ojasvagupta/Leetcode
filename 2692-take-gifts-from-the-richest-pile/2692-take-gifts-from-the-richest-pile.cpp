class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long res = 0;
        for (int i = 0; i < gifts.size(); i++) {
            pq.push(gifts[i]);
        }
        int n = 0;
        while (n < k) {
            int a = pq.top();
            pq.pop();
            a = sqrt(a);
            pq.push(a);
            n++;
        }
        while (!pq.empty()) {
            res = res + pq.top();
            pq.pop();
        }
        return res;
    }
};