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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool> mp;
        for(auto a:nums)
        {
            mp[a]=true;
        }
        ListNode* root=head;
        if(root->next==nullptr)
        {
            return head;
        }
        ListNode* nxt=root->next;
        ListNode* nxt2=nxt->next;
        while(nxt2!=nullptr)
        {
            if(mp.count(nxt->val))
            {
                root->next=nxt2;
                nxt=nxt2;
                nxt2=nxt2->next;
            }
           else{ root=nxt;
            nxt=nxt2;
            nxt2=nxt2->next;}
        }
        if(mp.count(head->val))
        {
            head=head->next;
        }
        if(mp.count(nxt->val))
        {
            root->next=nullptr;
        }
        return head;
        
    }
};