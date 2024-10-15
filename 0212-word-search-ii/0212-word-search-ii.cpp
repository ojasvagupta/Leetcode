class Node {
public:
    unordered_map<int, Node*> mp;
    bool end;

    Node() { end = false; }
};

class Solution {
public:
    void insertWord(Node* root, const string& word) {
        Node* current = root;
        for (char c : word) {
            if (!current->mp.count(c - 'a')) {
                current->mp[c - 'a'] = new Node();
            }
            current = current->mp[c - 'a'];
        }
        current->end = true;
    }

    void dfs(int i, int j, Node* root, vector<vector<char>>& board,
             vector<vector<bool>>& vis, string& currentWord,
             vector<string>& result) {

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            vis[i][j]) {
            return;
        }

        char ch = board[i][j];
        if (!root->mp.count(ch - 'a')) {
            return;
        }

        vis[i][j] = true;
        root = root->mp[ch - 'a'];
        currentWord.push_back(ch);

        if (root->end) {
            result.push_back(currentWord);
            root->end = false;
        }

        dfs(i + 1, j, root, board, vis, currentWord, result);
        dfs(i - 1, j, root, board, vis, currentWord, result);
        dfs(i, j + 1, root, board, vis, currentWord, result);
        dfs(i, j - 1, root, board, vis, currentWord, result);

        vis[i][j] = false;
        currentWord.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        Node* root = new Node();
        for (const string& word : words) {
            insertWord(root, word);
        }

        vector<string> result;
        vector<vector<bool>> vis(board.size(),
                                 vector<bool>(board[0].size(), false));
        string currentWord;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(i, j, root, board, vis, currentWord, result);
            }
        }

        return result;
    }
};
