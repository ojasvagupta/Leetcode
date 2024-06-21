class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size();
        r = r - 1;
        vector<int> v;
        int sum = numbers[l] + numbers[r];
        while (sum != target) {

            if (sum < target) {
                l = l + 1;
            } else {
                r = r - 1;
            }
            sum = numbers[l] + numbers[r];
        }
        v.push_back(l + 1);
        v.push_back(r + 1);

        return v;
    }
};