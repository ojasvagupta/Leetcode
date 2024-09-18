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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;  // Handle edge cases

        // Create two dummy nodes for the two partitions: less than and greater than or equal to x
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);
        
        ListNode* less = lessHead;
        ListNode* greater = greaterHead;
        
        // Traverse the original list
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        
        // Terminate the greater list to avoid cycles
        greater->next = nullptr;
        
        // Connect the less list to the greater list
        less->next = greaterHead->next;
        
        // Return the head of the new partitioned list
        return lessHead->next;
    }
};
