class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while (i < n - 2) {
            if (arr[i] % 2 != 0) {
                if (arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0) {
                    return true;
                }
            }
            i++;
        }
        return false;
    }
};