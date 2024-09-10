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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==nullptr)
        {
            return head;
        }
        ListNode* root=head;
        while(root!=nullptr)
        {
            ListNode* y=root->next;
            int a=root->val;
            int b=0;
            if(root->next!=nullptr)
            {
                b=root->next->val;
            }
            else
            {
                break;
            }
            int m=min(a,b);
            int gcf=1;
            for(int i=2;i<=a;i++)
            {
                if(a%i==0 && b%i==0)
                {
                    gcf=i;
                }
            }
            ListNode* x=new ListNode(gcf);
            root->next=x;
            x->next=y;
            root=y;
        }
        return head;
    }
};