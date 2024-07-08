

class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1)
            return 1;

        ListNode* head = new ListNode(1);
        ListNode* temp = head;
        for (int i = 2; i <= n; i++) {
            temp->next = new ListNode(i);
            temp = temp->next;
        }
        temp->next = head;

        ListNode* prev = temp;
        ListNode* curr = head;
        while (curr->next != curr) {

            for (int i = 1; i < k; i++) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }

        int winner = curr->val;
        delete curr;
        return winner;
    }
};
