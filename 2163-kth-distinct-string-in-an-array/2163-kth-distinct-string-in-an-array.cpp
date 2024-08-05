class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        int count = 0;
        for (auto n : arr) {
            if (mp[n] == 1) {
                count++;
                if (count == k)
                    return n;
            }
        }
        return "";
    }
};