class Solution {
public:
    int minimumPushes(string word) {
        sort(word.begin(), word.end());
        vector<int> v;
        unordered_map<char, int> mp;
        for (auto a : word) {
            if (mp.count(a)) {
                mp[a]++;
            } else {
                mp[a] = 1;
            }
        }
        for (auto a : mp) {
            v.push_back(a.second);
        }
        sort(v.begin(), v.end(), greater());

        int res = 0;
        int i = 1;
        for (int count = 0; count < v.size(); count++) {
            if (count % 8 == 0 && count != 0) {
                i = i + 1;
            }
            res = res + v[count] * i;
        }
        return res;
    }
};