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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp1 = head;
        ListNode* temp2 = temp1->next;
        ListNode* temp3 = temp2->next;
        vector<int> v;
        int sum = 1;
        while (temp3 != NULL) {
            sum++;
            if (((temp2->val) > (temp1->val) && (temp2->val) > (temp3->val)) || ((temp2->val) < (temp1->val) && (temp2->val) < (temp3->val))) {
                v.push_back(sum);
            }
            //if ((temp2->val) < (temp1->val) && (temp2->val) < (temp3->val)) {
              //  v.push_back(sum);
            //}
            temp1 = temp1->next;
            temp2 = temp1->next;
            temp3 = temp2->next;
        }
        int diff = 0;
        if (v.size() <= 1) {
            return {-1, -1};
        }
        int mini = INT_MAX;
        for (int i = 1; i < v.size(); i++) {
            diff = 0;
            diff = v[i] - v[i - 1];
            mini = min(mini, diff);
        }
        int max = v[v.size() - 1] - v[0];

        return {mini, max};
    }
};