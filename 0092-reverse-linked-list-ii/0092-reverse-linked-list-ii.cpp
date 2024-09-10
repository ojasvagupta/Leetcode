class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode* dummy =
            new ListNode(0); // Create a dummy node to simplify the edge case
                             // where head needs to be changed.
        dummy->next = head;
        ListNode* prev = dummy;

        // Move `prev` to the node before the `left` position.
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // `start` will point to the first node in the section to be reversed.
        ListNode* start = prev->next;
        ListNode* then = start->next;

        // Reverse the sublist between `left` and `right`.
        for (int i = 0; i < right - left; ++i) {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }

        return dummy->next; // Return the new head, which could be different if
                            // `left == 1`.
    }
};
