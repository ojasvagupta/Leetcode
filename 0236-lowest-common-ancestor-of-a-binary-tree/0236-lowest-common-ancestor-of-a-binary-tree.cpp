/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or either p or q is found, return root
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Recursively search in the left and right subtrees
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // If both left and right contain one of p or q, then root is the LCA
        if (leftLCA != nullptr && rightLCA != nullptr) {
            return root;
        }

        // Otherwise, return the non-null child (either leftLCA or rightLCA)
        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }
};
