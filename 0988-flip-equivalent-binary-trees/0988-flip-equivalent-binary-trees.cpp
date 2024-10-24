class Solution {
public:
    bool traverse(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
            return false;
        }

        // Check if they are equivalent without flipping, or by flipping.
        bool noFlip = traverse(root1->left, root2->left) && traverse(root1->right, root2->right);
        bool flip = traverse(root1->left, root2->right) && traverse(root1->right, root2->left);

        return noFlip || flip;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return traverse(root1, root2);
    }
};
