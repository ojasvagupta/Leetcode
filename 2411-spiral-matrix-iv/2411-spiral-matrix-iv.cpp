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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        if (m == 1 && n == 1) {
            return {{head->val}};
        }
        vector<vector<int>> v(m, vector<int>(n, -1));
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;
        ListNode* root = head;
        while (left <= right && top <= bottom && root != nullptr) {

            for (int i = left; i <= right && root != nullptr; i++) {
                
                v[top][i] = root->val;
                root = root->next;
            }
            top++;

            for (int i = top; i <= bottom && root != nullptr; i++) {
                
                v[i][right] = root->val;
                root = root->next;
            }
            right--;
            for (int i = right; i >= left && root != nullptr; i--) {
                
                v[bottom][i] = root->val;
                root = root->next;
            }
            bottom--;
            for (int i = bottom; i >= top && root != nullptr; i--) {
                
                v[i][left] = root->val;
                root = root->next;
            }
            left++;
        }
        return v;
    }
};