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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
                int n = q.size();
                for(int i = 0; i < n; i++) {
                    auto f = q.front();
                    q.pop();
                    TreeNode* node = f.first;
                    auto pos = f.second; 
                    int xpos = pos.first;
                    int ypos = pos.second;
                    if(node -> left) q.push({node -> left, {xpos - 1, ypos + 1}});
                    if(node -> right) q.push({node -> right, {xpos + 1, ypos + 1}});
                    mp[xpos].push_back({node -> val, ypos});
                }
        }

        vector<vector<int>> ans;
        for(auto i:mp) {
            sort(i.second.begin(), i.second.end(), [&](auto p1, auto p2) {
                if(p1.second == p2.second) {
                    return p1.first < p2.first;
                }
                return p1.second < p2.second;
            });
            vector<int> temp;
            for(auto j:i.second) {
                temp.push_back(j.first);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};