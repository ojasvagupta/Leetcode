struct TrieNode {
    vector<TrieNode*> children;
    bool isEnd;

    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    void calc(Trie& trie, string& s, int index, int n, vector<string>& v,
              string t, TrieNode* node) {
        if (index == n) {
            // remove trailing space, if any
            if (!t.empty() && t.back() == ' ')
                t.pop_back();
            v.push_back(t);
            return;
        }

        TrieNode* curr = node;

        for (int i = index; i < n; ++i) {
            char c = s[i];
            int idx = c - 'a';

            if (!curr->children[idx]) {
                break; // no further extension from this path
            }

            curr = curr->children[idx];

            if (curr->isEnd) {
                string nextWord = s.substr(index, i - index + 1);
                string nextString = t.empty() ? nextWord : t + " " + nextWord;
                calc(trie, s, i + 1, n, v, nextString, trie.root);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        Trie trie;
        for (string& word : wordDict)
            trie.insert(word);

        calc(trie, s, 0, s.size(), res, "", trie.root);

        return res;
    }
};
