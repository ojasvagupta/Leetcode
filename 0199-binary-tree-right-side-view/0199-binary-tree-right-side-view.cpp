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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
        {
            return {};
        }
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front == nullptr && !q.empty()) {
                q.push(nullptr);
            } else {
                if (front!=nullptr && front->left != nullptr) {
                    q.push(front->left);
                }
                if (front!=nullptr && front->right != nullptr) {
                    q.push(front->right);
                }
            }

            if (q.front() == nullptr && front != nullptr) {
                v.push_back(front->val);
            }
        }
        return v;
    }
};