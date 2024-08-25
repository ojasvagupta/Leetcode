/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void traversal(TreeNode* root,vector<int>& v)
{
    if(root==nullptr)
    {
        return;
    }
    traversal(root->left,v);
    traversal(root->right,v);
    v.push_back(root->val);
}

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        traversal(root,v);

        return v;

        
    }
};