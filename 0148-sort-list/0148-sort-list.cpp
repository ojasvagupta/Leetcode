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
ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // Dummy node to ease the merging process
        ListNode* tail = &dummy; // Tail pointer to build the merged list
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        // Append the remaining part of the non-empty list
        if (l1 != nullptr) tail->next = l1;
        else tail->next = l2;
        
        return dummy.next; // Return the head of the merged list
    }
ListNode* ascending(ListNode* head,int n)
{
    ListNode* one=head;
    ListNode* root=head;
    if (!head || !head->next) {
            return head;
        }
    for(int i=0;i<n/2-1;i++)
    {
        root=root->next;
    }
    ListNode* temp=root->next;
    if(temp==nullptr)
    {
        return temp;
    }
    root->next=nullptr;
    one=ascending(one,n/2);
    temp=ascending(temp,n-n/2);
    return merge(one,temp);
}
    ListNode* sortList(ListNode* head) {
        ListNode* root=head;
        int n=0;
        while(root!=nullptr)
        {
            n++;
            root=root->next;
        }
        root=head;
       return ascending(root,n);

        
    }
};