/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& v, int x) {
        if (root == nullptr) {
            return;
        }
        x= x*10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            v.push_back(x);
            return;
        }
        dfs(root->left, v, x);
        dfs(root->right, v, x);
    }
    int sumNumbers(TreeNode* root) {
        vector<int> v;
        dfs(root, v, 0);
        int res = 0;
        for (int i = 0; i < v.size(); i++) {
            res = res + v[i];
        }

        return res;
    }
};