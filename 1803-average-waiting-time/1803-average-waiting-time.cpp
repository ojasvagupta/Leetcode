class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int j = customers[0][1] + customers[0][0];
        double wait = customers[0][1];
        for (int i = 1; i < n; i++) {
            if (customers[i][0] <= j) {
                j = j + customers[i][1];
                wait = wait + j - customers[i][0];
            }
            if (customers[i][0] > j) {
                j = customers[i][0] + customers[i][1];
                wait = wait + customers[i][1];
            }
        }
        double avg = wait / n;
        return avg;
    }
};