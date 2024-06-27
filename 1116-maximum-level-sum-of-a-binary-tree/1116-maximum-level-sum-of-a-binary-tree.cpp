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
    unordered_map<int, int> mp;
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())

        {
            int sum = 0;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                sum = sum + node->val;
                q.pop();
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            mp[level] = sum;
            level++;
        }
        int maxsum = INT_MIN;
        level = 0;
        for (auto a : mp) {
            maxsum = max(maxsum, a.second);
        }
        for (auto a : mp) {
            if (a.second == maxsum) {
                level = a.first;
            }
        }
        return level;
    }
};