class Node {
public:
    int val[2];
    Node* left;
    Node* right;
    
    Node() {
        val[0] = -1;
        val[1] = -1;
        left = nullptr;
        right = nullptr;
    }
};

class MyCalendar {
public:
    Node* head;
    
    MyCalendar() {
        head = nullptr; // The root is initially null
    }
    
    bool search(int start, int end, Node* root) {
        if (root == nullptr) {
            return true; // No conflict found if we've reached a null node
        }
        
        // Check for overlap with current node's interval
        if (!(end <= root->val[0] || start >= root->val[1])) {
            return false; // Overlap found
        }
        
        // Recursively search left or right based on the start time
        if (start < root->val[0]) {
            return search(start, end, root->left);
        } else {
            return search(start, end, root->right);
        }
    }
    
    Node* insert(int start, int end, Node* root) {
        if (root == nullptr) {
            // Create a new node and insert it here
            Node* temp = new Node();
            temp->val[0] = start;
            temp->val[1] = end;
            return temp;
        }
        
        // Insert recursively into the correct subtree
        if (start < root->val[0]) {
            root->left = insert(start, end, root->left);
        } else {
            root->right = insert(start, end, root->right);
        }
        
        return root; // Return the (possibly unchanged) root node
    }
    
    bool book(int start, int end) {
        // Check if the new event overlaps with any existing event
        if (search(start, end, head)) {
            // If no conflict, insert the new event
            head = insert(start, end, head);
            return true;
        } else {
            return false; // Conflict found, cannot book this event
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start, end);
 */
