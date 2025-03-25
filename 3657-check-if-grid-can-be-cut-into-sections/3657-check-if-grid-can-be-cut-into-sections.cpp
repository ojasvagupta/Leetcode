class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> xaxis;
        vector<pair<int, int>> yaxis;
        for (int i = 0; i < rectangles.size(); i++) {
            xaxis.push_back({rectangles[i][0], rectangles[i][2]});
            yaxis.push_back({rectangles[i][1], rectangles[i][3]});
        }
        sort(xaxis.begin(), xaxis.end());
        sort(yaxis.begin(), yaxis.end());
        int countx = 0;
        int endx = xaxis[0].second;
        int county = 0;
        int endy = yaxis[0].second;
        for (int i = 1; i < xaxis.size(); i++) {
            if (endx <= xaxis[i].first) {
                countx++;
            }
            endx = max(endx, xaxis[i].second);
            if (endy <= yaxis[i].first) {
                county++;
            }
            endy = max(endy, yaxis[i].second);
        }
        if (countx >= 2 or county >= 2) {
            return true;
        }
        return false;
    }
};