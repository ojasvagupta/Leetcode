class Solution {
public:
    // Function to count the number of steps between curr and curr+1 within the limit n
    int countSteps(long curr, long n) {
        long steps = 0;
        long first = curr;
        long last = curr;
        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;  // Start with 1 because 0 is not a valid number
        k--;  // Decrease k because we consider the first number `1` as already counted

        while (k > 0) {
            int steps = countSteps(curr, n);
            if (steps <= k) {
                // If the steps to the next prefix are less than or equal to k,
                // move to the next prefix
                curr++;
                k -= steps;
            } else {
                // Otherwise, go deeper into the current prefix
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};
