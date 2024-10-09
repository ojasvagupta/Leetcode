#include <stack>

// Definition for a binary tree node.

class BSTIterator {
private:
    std::stack<TreeNode*> stack;
    
    // Helper function to push all left nodes onto the stack
    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            stack.push(node);
            node = node->left;
        }
    }
    
public:
    // Constructor: Initialize the iterator with the root of the BST
    BSTIterator(TreeNode* root) {
        // Push all the left nodes from the root to the leftmost leaf
        pushAllLeft(root);
    }
    
    // Returns the next smallest element in the in-order traversal
    int next() {
        // Get the top node in the stack (smallest unvisited node)
        TreeNode* topNode = stack.top();
        stack.pop();  // Remove it from the stack
        
        // If the node has a right child, push all its left children to the stack
        if (topNode->right != nullptr) {
            pushAllLeft(topNode->right);
        }
        
        return topNode->val;  // Return the node's value
    }
    
    // Returns true if there is a next element in the in-order traversal
    bool hasNext() {
        // If the stack is not empty, there's a next node to visit
        return !stack.empty();
    }
};
