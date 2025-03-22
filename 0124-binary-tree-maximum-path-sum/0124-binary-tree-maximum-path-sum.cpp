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
    int pathval(TreeNode*& root, int& res) {
        if(root==nullptr)
        {
            return 0;
        }
        int maxi = root->val;
        int left = pathval(root->left,res);
        int right = pathval(root->right,res);
        maxi = max(maxi, left + root->val);
        maxi = max(maxi, right + root->val);
        res = max(res, root->val + left + right);
        res=max(res,max(root->val+left,root->val+right));
        res=max(res,root->val);
        return maxi;
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        pathval(root,res);
        return res;

    }
};