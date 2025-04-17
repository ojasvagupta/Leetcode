#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) return res;

        int wordLen = words[0].size();
        int totalWords = words.size();
        int totalLen = wordLen * totalWords;

        unordered_map<string, int> wordFreq;
        for (auto& word : words) {
            wordFreq[word]++;
        }

        for (int i = 0; i < wordLen; i++) { // Shift starting points for overlapping cases
            int left = i, right = i;
            unordered_map<string, int> window;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.find(word) != wordFreq.end()) {
                    window[word]++;
                    while (window[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                    }

                    if (right - left == totalLen) {
                        res.push_back(left);
                    }
                } else {
                    window.clear();
                    left = right;
                }
            }
        }

        return res;
    }
};
