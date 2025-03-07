class Solution {
public:
    // Function to check if a number is prime
    bool check(int val) {
        if (val < 2)
            return false; // 0 and 1 are not prime
        for (int i = 2; i * i <= val; i++) {
            if (val % i == 0)
                return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> v(2, -1);
        int diff = INT_MAX;
        int first = -1;

        for (int i = left; i <= right; i++) {
            if (check(i)) {
                if (first == -1) {
                    first = i;
                } else {
                    int second = i;
                    if (second - first < diff) {
                        v[0] = first;
                        v[1] = second;
                        diff = second - first;
                        if (diff <= 2)
                            return v; // Early exit for closest primes
                    }
                    first = second; // Update first for the next iteration
                }
            }
        }

        return v;
    }
};
