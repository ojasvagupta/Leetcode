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
    void rez(TreeNode* root, int x, int& res) {
        if (root == nullptr) {
            return;
        }
        int sub = 0;
        if (x != root->val) {
            sub = abs(root->val - x);
            res = min(res, sub);
        }
        rez(root->left, x, res);
        rez(root->right, x, res);
    }

    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* f = q.front();
            q.pop();
            int res = INT_MAX;
                rez(root, f->val, res);
                diff = min(res, diff);
            
            if(f->left!=nullptr)
            {
                q.push(f->left);
            }
            if(f->right!=nullptr)
            {
                q.push(f->right);
            }
        }
        return diff;
    }
};