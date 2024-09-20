class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {}; // Edge case: if the tree is empty

        deque<TreeNode*> dq;
        vector<vector<int>> res;
        dq.push_back(root);
        bool leftToRight = true;

        while (!dq.empty()) {
            int size = dq.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = nullptr;

                if (leftToRight) {
                    node = dq.front();
                    dq.pop_front();
                    level[i] = node->val;

                    if (node->left)
                        dq.push_back(node->left);
                    if (node->right)
                        dq.push_back(node->right);
                } else {
                    node = dq.back(); 
                    dq.pop_back();
                    level[i] = node->val;

                    if (node->right)
                        dq.push_front(
                            node->right);
                    if (node->left)
                        dq.push_front(node->left);
                }
            }

            res.push_back(level);       // Add current level to result
            leftToRight = !leftToRight; // Alternate direction
        }

        return res;
    }
};
