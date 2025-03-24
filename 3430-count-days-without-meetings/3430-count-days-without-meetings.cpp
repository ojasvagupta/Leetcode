class Solution {
public:
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0]; // Min heap: smaller start time first
        }
    };

    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty())
            return days;

        // Push all meetings into the min heap
        priority_queue<vector<int>, vector<vector<int>>, Compare> minHeap;
        for (const auto& meeting : meetings) {
            minHeap.push(meeting);
        }

        int totalMeetingDays = 0;
        auto current = minHeap.top();
        minHeap.pop();
        int start = current[0], end = current[1];

        while (!minHeap.empty()) {
            auto next = minHeap.top();
            minHeap.pop();
            int newStart = next[0], newEnd = next[1];

            if (newStart <= end) {
                // Overlapping, merge intervals
                end = max(end, newEnd);
            } else {
                // No overlap, count current interval
                totalMeetingDays += (end - start + 1);
                start = newStart;
                end = newEnd;
            }
        }

        // Count the last interval
        totalMeetingDays += (end - start + 1);

        return days - totalMeetingDays;
    }
};
