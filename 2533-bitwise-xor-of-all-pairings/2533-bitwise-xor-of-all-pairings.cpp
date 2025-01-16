class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = 0;
        if (nums2.size() % 2 != 0) {
            for (int i = 0; i < nums1.size(); i++) {
                n1 = n1 ^ nums1[i];
            }
        }
        int n2 = 0;
        if (nums1.size() % 2 != 0) {
            for (int i = 0; i < nums2.size(); i++) {
                n2 = n2 ^ nums2[i];
            }
        }
        return n1 ^ n2;
    }
};