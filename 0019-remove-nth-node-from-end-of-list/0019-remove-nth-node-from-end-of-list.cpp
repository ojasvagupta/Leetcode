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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count = count + 1;
            temp = temp->next;
        }
        temp = head;
        if (count == n && count != 1) {
            temp = temp->next;
            head = temp;
        } else if (count == 1) {
            temp->next = NULL;
            temp = temp->next;
            head = temp;
        } else {
            for (int i = 1; i < (count - n); i++) {
                temp = temp->next;
            }
            ListNode* nexnex = temp->next->next;
            temp->next = nexnex;
        }
        return head;
    }
};