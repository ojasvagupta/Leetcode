class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0]>=intervals[i-1][0] && intervals[i][1]<=intervals[i-1][1])
            {
                intervals[i][0]=intervals[i-1][0];
                intervals[i][1]=intervals[i-1][1];
                res.back()[0]=intervals[i][0];
            }
            else if(intervals[i][0]>=intervals[i-1][0] && intervals[i][0]<=intervals[i-1][1] && intervals[i][1]>intervals[i-1][1])
            {
                intervals[i][0]=intervals[i-1][0];
                intervals[i-1][1]=intervals[i][1];
                res.back()[1]=intervals[i][1];
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};