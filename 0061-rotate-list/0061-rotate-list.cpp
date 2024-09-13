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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr or head->next==nullptr)
        {
            return head;
        }
        ListNode* root=head;
        int count=0;
        while(root!=nullptr)
        {
            root=root->next;
            count++;
        }
        if(k>=count)
        {
            k=k%count;
        }
        if(k==0)
        {
            return head;
        }
        root=head;
        for(int i=1;i<count-k;i++)
        {
            root=root->next;
        }
        ListNode* start=root;
        while(root->next!=nullptr)
        {
            root=root->next;
        }
        root->next=head;
        ListNode* head1=start->next;
        start->next=nullptr;
        return head1;
        
    }
};