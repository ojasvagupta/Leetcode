class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0; // to keep track of the imbalance between opening and closing brackets
        int maxImbalance = 0; // to keep track of the maximum imbalance

        // Traverse through the string to calculate the imbalance
        for (char c : s) {
            if (c == '[') {
                imbalance++; // opening bracket increases balance
            } else {
                imbalance--; // closing bracket decreases balance
            }
            // Track the maximum imbalance
            maxImbalance = min(maxImbalance, imbalance);
        }

        // The number of swaps needed is half of the absolute maximum imbalance
        // because each swap can fix two unbalanced brackets (a '[' and a ']')
        return (-maxImbalance + 1) / 2;
    }
};
