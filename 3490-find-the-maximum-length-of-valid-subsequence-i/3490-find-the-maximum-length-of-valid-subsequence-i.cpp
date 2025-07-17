class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<char> v;
        int e1 = 0;
        int o1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                e1++;
                v.push_back('e');
            } else {
                o1++;
                v.push_back('o');
            }
        }
        int count = 1;
        char a = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (a != v[i]) {
                a = v[i];
                count++;
            }
        }
        return max(max(e1, o1), count);
    }
};