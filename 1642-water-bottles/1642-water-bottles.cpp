class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles;
        int left = empty % numExchange;
        int use = empty / numExchange;
        int sum = numBottles;
        while (left != empty) {
            sum = sum + use;
            empty = left + use;
            left = empty % numExchange;
            use = empty / numExchange;
        }
        return sum;
    }
};