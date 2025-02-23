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
    TreeNode* create(int prestart, int poststart, int preend,
                     vector<int>& preorder, unordered_map<int, int>& mp) {

        if (prestart > preend) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[prestart]);
        if (prestart == preend) {
            return root;
        }

        int j = poststart;
        if (prestart + 1 < preorder.size()) {
            j = mp[preorder[prestart + 1]];
        }

        int num = j - poststart + 1;
        root->left =
            create(prestart + 1, poststart, prestart + num, preorder, mp);
        root->right = create(prestart + num + 1, j + 1, preend, preorder, mp);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < postorder.size(); i++) {
            mp[postorder[i]] = i;
        }
        return create(0, 0, preorder.size() - 1, preorder, mp);
    }
};