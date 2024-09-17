class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* current = root;
        while (current) {
            if (current->left) {
                TreeNode* pre = current->left;
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = current->right;
                current->right = current->left;
                current->left = nullptr;
            }
             current = current->right;
        }
    }
};
