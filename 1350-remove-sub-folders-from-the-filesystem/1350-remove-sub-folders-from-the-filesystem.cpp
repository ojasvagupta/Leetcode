class TrieNode {
public:
    bool isEnd; // marks end of a word
    unordered_map<string, TrieNode*> children;

    TrieNode() { isEnd = false; }
};
class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    bool insert(const string& word) {
        string s = "";
        TrieNode* curr = root;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == '/') {
                if (!curr->children.count(s)) {
                    if (curr->isEnd) {
                        return false;
                    }
                    curr->children[s] = new TrieNode();
                }
                curr = curr->children[s];
                s = "";
            } else {
                s = s + word[i];
            }
        }
        if (curr->children.count(s)) {
            if (curr->children[s]->isEnd)
                return false;
        } else {
            if (curr->isEnd)
                return false;
            curr->children[s] = new TrieNode();
        }

        curr = curr->children[s]; 
        curr->isEnd = true;     
        return true;
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        Trie trie;
        for (int i = 0; i < folder.size(); i++) {
            if (trie.insert(folder[i])) {
                res.push_back(folder[i]);
            }
        }
        return res;
    }
};