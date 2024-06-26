class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        int first = 0;
        int last = x;
        int mid = 0;
        while (first <= last) {
            mid = (last + first) / 2;
            long long square = static_cast<long long>(mid) * mid;

            if (square == x)
                return mid;
            if (square > x)
                last = mid - 1;
            else {
                first = mid + 1;
            }
        }
        return static_cast<int>(round(last));
    }
};