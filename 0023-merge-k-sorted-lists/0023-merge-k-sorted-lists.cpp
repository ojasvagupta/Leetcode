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
struct Compare {
    bool operator()(const pair<int, ListNode*>& a, const pair<int, ListNode*>& b) {
        return a.first > b.first; // Min heap condition
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
        {
            return nullptr;
        }
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Compare> pq;
        for(auto a : lists)
        {
            if(a!=nullptr)
            {
                pq.push(make_pair(a->val,a));
            }
            
        }
        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;
        while(!pq.empty())
        {
            auto x=pq.top();
            dummy->next=x.second;
            dummy=dummy->next;
            pq.pop();
            x.second=x.second->next;
            if(x.second!=nullptr)
            {
                pq.push(make_pair(x.second->val,x.second));
            }
        }
        dummy=head->next;
        delete head;
        return dummy;

    }
};