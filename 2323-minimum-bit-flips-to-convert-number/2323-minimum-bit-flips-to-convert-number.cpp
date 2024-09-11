class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorValue = start ^ goal;
        int flips = 0;

        while (xorValue > 0) {
            flips += xorValue & 1; 
            xorValue >>= 1;
        }

        return flips;
    }
};
