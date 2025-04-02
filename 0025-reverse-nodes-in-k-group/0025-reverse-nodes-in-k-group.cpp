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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=1;
        ListNode* travel=head;
        while(travel->next!=nullptr)
        {
            n++;
            travel = travel->next;
        }
        if (n < k) return head;
        if(n==k)
        {
            ListNode* prev=nullptr;
            ListNode* curr=head;
            ListNode* nxt=curr->next;
            while(curr!=nullptr)
            {
                curr->next=prev;
                prev=curr;
                curr=nxt;
                if(nxt==nullptr)
                {
                    break;
                }
                nxt=nxt->next;
            }
            return prev;
        }
        ListNode* S1=new ListNode(-1);
        S1->next=head;
        ListNode* S2=head;
        ListNode* temp=head;
        ListNode* e1=nullptr;
        ListNode* e2=nullptr;
        travel=head;
        for(int i=1;i<k;i++)
        {
            travel=travel->next;
        }
        ListNode* res=travel;
        for(int i=1;i<=n;i++)
        {
            if(i%k==0)
            {
                e1=temp;
                e2=temp->next;
                travel=nullptr;
                ListNode* a=S2;
                ListNode* b=a->next;
                while(a!=e2)
                {
                    a->next=travel;
                    travel=a;
                    a=b;
                    if(b==nullptr)
                    {
                        break;
                    }
                    b=b->next;
                }
                S2->next=e2;
                S1->next=e1;
                S1=S2;
                S2=e2;
                temp=S2;
            }
            else
            {
                temp=temp->next;
            }
            
        }
        return res;
    }
};