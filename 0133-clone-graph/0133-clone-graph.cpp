/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone(Node* node, unordered_map<Node*, Node*>& mp) {
        Node* newnode = new Node(node->val);
        mp[node] = newnode;
        for(auto nebour : node->neighbors)
        {
            if(!mp.count(nebour))
            {
                (newnode->neighbors).push_back(clone(nebour,mp));
            }
            else
            {
                (newnode->neighbors).push_back(mp[nebour]);
            }
        }
        return newnode;
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        unordered_map<Node*, Node*> mp;
        return clone(node, mp);
    }
};