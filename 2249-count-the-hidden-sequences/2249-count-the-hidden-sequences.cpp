class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long min_prefix = 0, max_prefix = 0, current = 0;
        for (auto diff : differences) {
            current += diff;
            min_prefix = min(min_prefix, current);
            max_prefix = max(max_prefix, current);
        }
        long long min_start = lower - min_prefix;
        long long max_start = upper - max_prefix;
        if (min_start > max_start) return 0;
        return (int)(max_start - min_start + 1);
    }
};
