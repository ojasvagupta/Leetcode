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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        int cnt=0;
        double sum=0;
        q.push(root);
        q.push(NULL);
            TreeNode* a=nullptr;
            while (!q.empty()) {
            TreeNode* a = q.front();
            q.pop();
            if(a==NULL)
            {
                double avg=sum/cnt;
                res.push_back(avg);
                cnt=0;
                sum=0;
                if(q.size()>0)
                {
                    q.push(NULL);
                }
            }
            else
            {
                sum=sum+a->val;
                cnt++;
                if(a->left)
                {
                    q.push(a->left);
                }
                if(a->right)
                {
                    q.push(a->right);
                }
            }
        }
     return res;   
    }
};