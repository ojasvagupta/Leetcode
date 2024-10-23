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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, int> mp;
        mp[1] = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int sum = 0;
        int i = 2;
        while (!q.empty()) {
            if (q.front() == nullptr) {
                q.pop();
                mp[i] = sum;
                sum = 0;
                i++;
                if (q.empty() == false) {
                    q.push(nullptr);
                }

            } else {
                TreeNode* front = q.front();
                q.pop();
                if (front->left) {
                    sum = sum + front->left->val;
                    q.push(front->left);
                }
                if (front->right) {
                    sum = sum + front->right->val;
                    q.push(front->right);
                }
            }
        }
        q.push(root);
        q.push(nullptr);
        i = 2;
        sum = mp[i];

        while (!q.empty()) {
            if (q.front() == nullptr) {
                q.pop();

                if (q.empty() == false) {
                    q.push(nullptr);
                } else {
                    break;
                }
                i++;
                sum = mp[i];

            } else {
                TreeNode* front = q.front();
                sum = mp[i];
                q.pop();
                if (front->left) {
                    sum = sum - front->left->val;
                    q.push(front->left);
                }
                if (front->right) {
                    sum = sum - front->right->val;
                    q.push(front->right);
                }
                if (front->left) {
                    front->left->val = sum;
                }
                if (front->right) {
                    front->right->val = sum;
                }
            }
        }
        root->val = 0;
        return root;
    }
};