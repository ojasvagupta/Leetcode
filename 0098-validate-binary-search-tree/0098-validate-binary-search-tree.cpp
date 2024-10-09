class Solution {
public:
    bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN,
                    long long maxVal = LLONG_MAX) {
        if (!root)
            return true; // An empty tree is a valid BST

        // Check if the current node's value is within the allowed range
        if (root->val <= minVal || root->val >= maxVal)
            return false;

        // Recursively validate the left and right subtrees with updated ranges
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }
};
