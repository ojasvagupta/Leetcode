class Solution {
public:
    int minCostHelper(vector<int>& days, vector<int>& costs, int i, vector<int>& memo) {
        // Base case: If all travel days are covered
        if (i >= days.size()) {
            return 0;
        }

        // If already calculated, return the memoized result
        if (memo[i] != -1) {
            return memo[i];
        }

        // Option 1: Buy a 1-day pass
        int option1 = costs[0] + minCostHelper(days, costs, i + 1, memo);

        // Option 2: Buy a 7-day pass
        int j = i;
        while (j < days.size() && days[j] < days[i] + 7) {
            j++;
        }
        int option2 = costs[1] + minCostHelper(days, costs, j, memo);

        // Option 3: Buy a 30-day pass
        j = i;
        while (j < days.size() && days[j] < days[i] + 30) {
            j++;
        }
        int option3 = costs[2] + minCostHelper(days, costs, j, memo);

        // Store the result in memo and return the minimum cost
        return memo[i] = min({option1, option2, option3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size(), -1); // Initialize memoization array
        return minCostHelper(days, costs, 0, memo); // Start from the first day
    }
};
