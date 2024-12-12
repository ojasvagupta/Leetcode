class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, currentGas = 0, startStation = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];

            // If currentGas is negative, reset the start station
            if (currentGas < 0) {
                startStation = i + 1;
                currentGas = 0;
            }
        }

        // Check if total gas is sufficient
        return (totalGas >= totalCost) ? startStation : -1;
    }
};
