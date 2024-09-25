#include <unordered_map>
#include <string>
using namespace std;

class tNode {
public:
    bool end;
    unordered_map<int, tNode*> mp;
    
    tNode() {
        end = false;  // Initially, the node doesn't represent the end of a word
    }
};

class Trie {
public:
    tNode* root;

    Trie() {
        root = new tNode();  // Initialize root node
    }
    
    void insert(string word) {
        tNode* node = root;  // Start from the root
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';  // Calculate the index for the current character
            if (!node->mp.count(index)) {
                node->mp[index] = new tNode();  // If character not present, create a new node
            }
            node = node->mp[index];  // Move to the next node
        }
        node->end = true;  // Mark the end of the word
    }
    
    bool search(string word) {
        tNode* node = root;  // Start from the root
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';  // Calculate the index for the current character
            if (!node->mp.count(index)) {
                return false;  // If character not found, return false
            }
            node = node->mp[index];  // Move to the next node
        }
        return node->end;  // Return true if it's the end of a valid word
    }
    
    bool startsWith(string prefix) {
        tNode* node = root;  // Start from the root
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';  // Calculate the index for the current character
            if (!node->mp.count(index)) {
                return false;  // If character not found, return false
            }
            node = node->mp[index];  // Move to the next node
        }
        return true;  // If prefix matches, return true
    }
};

