class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> proom; // available rooms
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> broom; // {endTime, roomIndex}

        for (int i = 0; i < n; i++) {
            proom.push(i);
        }

        vector<int> v(n, 0); // room usage

        for (int i = 0; i < meetings.size(); i++) {
            long long start = meetings[i][0];
            long long end = meetings[i][1];
            long long duration = end - start;

            // Free up rooms that have finished by this start time
            while (!broom.empty() && broom.top().first <= start) {
                proom.push(broom.top().second);
                broom.pop();
            }

            if (!proom.empty()) {
                int room = proom.top(); proom.pop();
                broom.push({end, room});
                v[room]++;
            } else {
                auto [endTime, room] = broom.top(); broom.pop();
                broom.push({endTime + duration, room});
                v[room]++;
            }
        }

        int idx = 0;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] > v[idx]) {
                idx = i;
            }
        }

        return idx;
    }
};
