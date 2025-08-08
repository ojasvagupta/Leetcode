class Solution {
public:
    vector<vector<double>> dp;

    double calc(int n1, int n2) {
        if (n1 <= 0 && n2 <= 0) return 0.5;
        if (n1 <= 0) return 1.0;
        if (n2 <= 0) return 0.0;

        if (dp[n1][n2] != -1.0) return dp[n1][n2];

        dp[n1][n2] = 0.25 * (
            calc(n1 - 100, n2) +
            calc(n1 - 75, n2 - 25) +
            calc(n1 - 50, n2 - 50) +
            calc(n1 - 25, n2 - 75)
        );

        return dp[n1][n2];
    }

    double soupServings(int n) {
        if (n > 4800) return 1.0; // For large n, answer approaches 1

        int m = ceil(n / 25.0); // Convert to units of 25ml
        dp = vector<vector<double>>(m * 25 + 1, vector<double>(m * 25 + 1, -1.0));
        return calc(n, n);
    }
};
