class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for (int i = 0; i < timePoints.size(); i++) {

            string a = timePoints[i].substr(0, 2);
            int hours = stoi(a);
            a = timePoints[i].substr(3, 2);
            int min = (hours) * 60 + stoi(a);

            v.push_back(min);
        }
        sort(v.begin(), v.end());
        int res = INT_MAX;
        int diff = 1440 - v.back() + v[0];
        res = min(res, diff);
        for (int i = 1; i < v.size(); i++) {
            diff = (v[i] - v[i - 1]);
            res = min(res, diff);
        }

        return res;
    }
};