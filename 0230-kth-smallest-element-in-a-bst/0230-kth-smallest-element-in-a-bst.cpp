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
    void traverse(TreeNode* root, int k, int& kmin, int& count) {
        if (root == nullptr || count == k) {
            return;
        }

        traverse(root->left, k, kmin, count);
        
            count++;
            if(count==k)
            {
                kmin = root->val;
                return;
            }
            
        
        traverse(root->right, k, kmin, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int min = -1;
        int count = 0;
        traverse(root, k, min, count);
        return min;
    }
};