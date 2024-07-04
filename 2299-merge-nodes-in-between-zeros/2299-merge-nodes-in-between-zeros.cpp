class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* curr=head->next;
        ListNode* prev=head;

        int sum=0;

        while(curr!=NULL)
        {
            if(curr->val==0)
            {
                curr->val=sum;
                prev->next=curr;
                prev=curr;
                sum=0;
            }
            else
            {
                sum+=curr->val;
            }
            curr=curr->next;
        }

        return head->next;
    }
};
