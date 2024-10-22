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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return -1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<long long> v;
        long long sum = 0;
        while (!q.empty()) {
            if (q.front() != nullptr) {
                TreeNode* front = q.front();
                q.pop();
                sum = sum + front->val;
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }

            } else {
                v.push_back(sum);
                sum=0;
                q.pop();
                if(!q.empty())
                {
                    q.push(nullptr);
                }
                
            }
        }
        if(v.size()<k)
        {
            return -1;
        }
        sort(v.begin(),v.end(),greater());
        return v[k-1];
    }
};