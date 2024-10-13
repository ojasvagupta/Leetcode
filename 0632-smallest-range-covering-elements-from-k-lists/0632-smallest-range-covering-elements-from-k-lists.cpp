class Tracker {
public:
    int val;
    int ldx;
    int edx;
    Tracker(int a, int b, int c) {
        val = a;
        edx = c;
        ldx = b;
    }
};
struct Compare {
    bool operator()(const Tracker& a, const Tracker& b) {
        return a.val > b.val; // Min-heap based on val
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Tracker, vector<Tracker>, Compare> track;
        int n = nums.size();
        int maxVal = INT_MIN;
        int start = 0;
        int end = INT_MAX;

        for (int i = 0; i < n; i++) {
            int val = nums[i][0];
            track.push(Tracker(val, i, 0));
            maxVal = max(maxVal, val);
        }
        while (track.size() == n) {
            Tracker temp = track.top();
            track.pop();

            if (maxVal - temp.val < end - start) {
                start = temp.val;
                end = maxVal;
            }

            if (temp.edx + 1 < nums[temp.ldx].size()) {
                int nextVal = nums[temp.ldx][temp.edx + 1];
                track.push(Tracker(nextVal, temp.ldx, temp.edx + 1));
                maxVal = max(maxVal, nextVal);
            }
        }
        return {start, end};
    }
};