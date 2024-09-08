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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* root = head;
        int size = 0;
        vector<ListNode*> res;
        while (root != nullptr) {
            size++;
            root = root->next;
        }
        root = head;
        if (size <= k) {
            int a = 1;
            while (a <= k) {
                if (a <=size) {

                    ListNode* ls = root->next;

                    root->next = nullptr;
                    res.push_back(root);
                    if(ls!=nullptr)
                    {
                        root = ls;
                    }
                    
                } else {
                    res.push_back(NULL);
                }
                a++;
            }
        }
        if(size>k)
        {
            int n=size/k;
            int m=size%k;
            vector<int> partSize(k,n);
            int i=0;
            for(int h=0;h<m;h++)
            {
                partSize[h]++;
            }
            ListNode* l=root;
            for(int x=0;x<partSize.size();x++)
            {

                for(int j=1;j<partSize[x];j++)
                {
                    root=root->next;
                }
                head=root->next;
                root->next=nullptr;
                res.push_back(l);
                root=head;
                l=root;
                
            }

        }
        return res;
    }
};