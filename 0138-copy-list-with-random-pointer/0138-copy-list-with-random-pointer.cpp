/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* root1 = head->next;
        Node* root2 = new Node(head->val);
        Node* head2 = root2;

        while (root1 != nullptr) {
            root2->next =new  Node(root1->val);
            root2 = root2->next;
            root1 = root1->next;
        }
        root1 = head;
        root2 = head2;
        Node* l=root2;
        Node* temp=root1;
        while(temp!=nullptr)
        {
            
            Node* rand1=temp->random;
            while(root1!=rand1)
            {
                root1=root1->next;
                root2=root2->next;
            }
            l->random=root2;
            l=l->next;
            temp=temp->next;
            
            root2=head2;
            root1=head;
        }
        return head2;
    }
};