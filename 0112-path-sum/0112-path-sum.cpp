class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr && targetSum == root->val) return true;
        bool l = hasPathSum(root->left,  targetSum - root->val);
        bool r = hasPathSum(root->right, targetSum - root->val);
        return l | r;
    }
};