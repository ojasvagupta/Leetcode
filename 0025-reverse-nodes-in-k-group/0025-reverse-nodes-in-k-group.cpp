class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;  // Edge case: empty list or k = 1 (no change)
        
        ListNode dummy(-1);  // Dummy node to simplify edge cases
        dummy.next = head;
        ListNode *prev = &dummy, *curr = head;
        
        // Count the number of nodes in the list
        int n = 0;
        while (curr) {
            n++;
            curr = curr->next;
        }

        if (n < k) return head;  // If fewer than k nodes, return as it is
        
        curr = head;
        while (n >= k) {  
            ListNode* next = curr->next;
            ListNode* tail = curr;  // Tail will become the last node after reversal
            
            // Reverse k nodes
            ListNode* prevNode = nullptr;
            for (int i = 0; i < k; i++) {
                ListNode* nextNode = curr->next;
                curr->next = prevNode;
                prevNode = curr;
                curr = nextNode;
            }
            
            // Connect reversed part with previous part
            prev->next = prevNode;
            tail->next = curr;
            prev = tail;
            n -= k;
        }
        
        return dummy.next;
    }
};
