/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void dfs(TreeNode* root,TreeNode* parent,unordered_set<TreeNode*> &values,vector<TreeNode*>& dsu,int i,int& maxi)
{
    if(root==nullptr)
    {
        if(i==maxi)
        {
            values.insert(parent);
        }
        if(i>maxi)
        {
            values.clear();
            maxi=i;
            values.insert(parent);
        }
        return;
    }
    dsu[root->val]=parent;
    dfs(root->left,root,values,dsu,i+1,maxi);
    dfs(root->right,root,values,dsu,i+1,maxi);
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> dsu(1001);
        unordered_set<TreeNode*> values;
        int maxi=0;
        TreeNode* temp=new TreeNode();
        dfs(root,temp,values,dsu,0,maxi);
        
        while(values.size()>1)
        {
            unordered_set<TreeNode*> st;
            for(auto a : values)
            {
                TreeNode* x=dsu[a->val];
                if(!st.count(x))
                {
                    st.insert(x);
                }
            }
            values=st;
        }
        for( auto a : values)
        {
            return a;
        }
        return temp;
    }
};