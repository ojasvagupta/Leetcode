class TrieNode {
    public:
    bool end;
    TrieNode* arr[10];
    TrieNode() {
        end = false;
        for (int i = 0; i < 10; i++) {
            arr[i] = nullptr;
        }
    }
};

class Solution {
public:
    void insert(string s, TrieNode* root) {
        TrieNode* curr=root;
        for (int i = 0; i < s.size(); i++) {
            if (curr->arr[s[i] - '0'] == nullptr) {
                curr->arr[s[i] - '0'] = new TrieNode();
                curr = curr->arr[s[i] - '0'];
            } else {
                curr = curr->arr[s[i] - '0'];
            }
        }
        curr->end = true;
    }
    int lcp(string s, TrieNode* root) {
        int count = 0;
        TrieNode* curr=root;
        for (int i = 0; i < s.size(); i++) {
            if (curr->arr[s[i] - '0'] !=nullptr) {
                count++;
                curr = curr->arr[s[i] - '0'];
            } else {
                return count;
            }
        }
        return count;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxi = 0;
        TrieNode* Node = new TrieNode();
        for (auto a : arr1) {
            TrieNode* root = Node;
            string s = to_string(a);
            insert(s, root);
        }
        for (auto a : arr2) {
            TrieNode* root = Node;
            string s = to_string(a);
            int x = lcp(s, root);
            maxi = max(maxi, x);
        }
        return maxi;
    }
};