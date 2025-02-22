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
void clc(TreeNode*& root, int v) {

    if (root->left) {
        root->left->val = 2 * root->val + 1;
        clc(root->left, 2 * v + 1);
    }
    if (root->right) {
        root->right->val = 2 * root->val + 2;
        clc(root->right, 2 * v + 2);
    }
    return;
}
class FindElements {
public:
    unordered_set<int> st;
    FindElements(TreeNode* root) { clc(root, 0); }
    void clc(TreeNode*& root, int v) {
        st.insert(v);
        if (root->left) {
            root->left->val = 2 * root->val + 1;
            clc(root->left, 2 * v + 1);
        }
        if (root->right) {
            root->right->val = 2 * root->val + 2;
            clc(root->right, 2 * v + 2);
        }
        return;
    }
    bool find(int target) {
        if(st.count(target))
        {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */