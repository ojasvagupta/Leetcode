/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        Node* temp = root;
        q.push(temp);
        q.push(NULL);
        while (!q.empty()) {
            Node* first = q.front();
            q.pop();
            Node* second = q.front();

            if (first != NULL) {
                first->next = second;
                if (first->left)
                    q.push(first->left);
                if (first->right)
                    q.push(first->right);
            }

            if (q.front() == NULL) {
                q.push(NULL);
                q.pop();
            }
        }
        return root;
    }
};