class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1,
            right = *max_element(quantities.begin(), quantities.end());
        int res = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int requiredStores = 0;

            // Calculate the number of stores needed if max per store is mid
            for (int quantity : quantities) {
                requiredStores += (quantity + mid - 1) /
                                  mid; // Equivalent to ceil(quantity / mid)
            }

            if (requiredStores <= n) {
                res = mid; // Try to minimize the maximum value
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return res;
    }
};
