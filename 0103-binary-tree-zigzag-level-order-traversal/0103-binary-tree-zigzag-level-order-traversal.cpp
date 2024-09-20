class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};  // Edge case: if the tree is empty

        deque<TreeNode*> dq;
        vector<vector<int>> res;
        dq.push_back(root);
        bool leftToRight = true;  // Flag to control direction

        while (!dq.empty()) {
            int size = dq.size();
            vector<int> level(size);  // Store current level values

            for (int i = 0; i < size; i++) {
                TreeNode* node = nullptr;
                
                if (leftToRight) {
                    node = dq.front();  // Process nodes from the front
                    dq.pop_front();
                    level[i] = node->val;
                    
                    if (node->left) dq.push_back(node->left);   // Push children left to right
                    if (node->right) dq.push_back(node->right);
                } else {
                    node = dq.back();  // Process nodes from the back
                    dq.pop_back();
                    level[i] = node->val;
                    
                    if (node->right) dq.push_front(node->right);  // Push children right to left
                    if (node->left) dq.push_front(node->left);
                }
            }
            
            res.push_back(level);  // Add current level to result
            leftToRight = !leftToRight;  // Alternate direction
        }
        
        return res;
    }
};
