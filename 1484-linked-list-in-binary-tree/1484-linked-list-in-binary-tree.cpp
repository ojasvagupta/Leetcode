/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool res(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true;
        }
        if(root==nullptr)
        {
            return false;
        } 
        
        if (head->val != root->val) {
            return false;
        }
        // Recursively check the left and right subtrees
        return res(head->next, root->left) || res(head->next, root->right);
    }
    void check(ListNode* head, TreeNode* root, bool& out) {
        if (root == nullptr) {
            return;
        }
        if (root->val == head->val && res(head,root)) {
            
                out = true;
            }
        
        if(out==true)
        {
            return;
        }
        check(head, root->left, out);
        check(head, root->right, out);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        bool out = false;
        check(head, root, out);
        return out;
    }
};