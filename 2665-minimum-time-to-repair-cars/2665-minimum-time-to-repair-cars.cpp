class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = (long long)*min_element(ranks.begin(), ranks.end()) *
                         cars * (long long)cars;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;

            for (int rank : ranks) {
                count += (long long)(sqrt(mid / (double)rank));
            }

            if (count >= cars) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
