class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());
        int start = meetings[0][0], end = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++) {
            int newStart = meetings[i][0];
            int newEnd = meetings[i][1];

            if (newStart <= end) {
                // Merge intervals
                end = max(end, newEnd);
            } else {
                // Add previous interval's days
                days -= (end - start + 1);
                start = newStart;
                end = newEnd;
            }
        }

        // Add last interval's days
        days -= (end - start + 1);

        return days;
    }
};
