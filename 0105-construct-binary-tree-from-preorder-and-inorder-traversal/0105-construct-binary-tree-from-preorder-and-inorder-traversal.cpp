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
int findPos( vector<int>& inorder,int element)
{
    for(int i=0;i<inorder.size();i++)
    {
        if(inorder[i]==element)
        {
            return i;
        }
    }
    return -1;
}
TreeNode* Solve(vector<int>& preorder, vector<int>& inorder,int& index,int inStart,int inEnd)
{
    if(index >=preorder.size() || inStart>inEnd)
    {
        return NULL;
    }
    int element=preorder[index];
    TreeNode* root=new TreeNode(element);
    index++;
    int pos=findPos(inorder,element);
    root->left=Solve(preorder,inorder,index,inStart,pos-1);
    root->right=Solve(preorder,inorder,index,pos+1,inEnd);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        TreeNode* root=Solve(preorder,inorder,index,0,inorder.size()-1);
        return root;
        
    }
};