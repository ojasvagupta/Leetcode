class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;
        bool res = 0;
        for (int i = 0; i < magazine.length(); i++) {
            if (mp.count(magazine[i])) {

                mp[magazine[i]]++;
            } else {
                mp[magazine[i]] = 1;
            }
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            if (mp2.count(ransomNote[i])) {
                mp2[ransomNote[i]]++;
            } else {
                mp2[ransomNote[i]] = 1;
            }
        }
        for (auto itr = mp2.begin(); itr != mp2.end(); itr++) {
            if (mp[itr->first] >= itr->second) {
                res = 1;
            } else {
                res = 0;
                break;
            }
        }
        return res;
    }
};