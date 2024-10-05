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
void makeTree(vector<int>& nums,TreeNode*& root,int start,int end)
{
    if(start>end)
    {
        root=nullptr;
        return;
    }
    int mid=(start+end)/2;
    TreeNode* temp=new TreeNode(nums[mid]);
    root=temp;
    
    makeTree(nums,root->left,start,mid-1);
    makeTree(nums,root->right,mid+1,end);
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start=0;
        int end=nums.size();
        TreeNode* root=nullptr;
        makeTree(nums,root,start,end-1);
        return root;
        
    }
};