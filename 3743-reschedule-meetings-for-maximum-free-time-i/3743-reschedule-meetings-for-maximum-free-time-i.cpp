class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<int> v;
        v.push_back(startTime[0]);
        for (int i = 0; i < n - 1; i++) {
            v.push_back(startTime[i + 1]-endTime[i]);
        }
        if (endTime[n - 1] < eventTime) {
              v.push_back(eventTime-endTime[n - 1]);
        }
        int left=0;
        int maxFree = 0, currSum = 0;
       for (int right = 0; right < v.size(); right++) {
            currSum += v[right];

            // Ensure window size does not exceed `k`
            if (right - left > k) {
                currSum -= v[left];
                left++;
            }

            maxFree = max(maxFree, currSum);
        }
        return maxFree;
    }
};