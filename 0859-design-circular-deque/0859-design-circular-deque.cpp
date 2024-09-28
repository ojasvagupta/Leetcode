class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int value = 0) : val(value), next(nullptr), prev(nullptr) {}
};

class MyCircularDeque {
public:
    int size;
    int capacity;
    Node* front;
    Node* back;

    MyCircularDeque(int k) : size(0), capacity(k), front(nullptr), back(nullptr) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = back = newNode;
            front->next = front->prev = front;
        } else {
            newNode->next = front;
            newNode->prev = back;
            front->prev = newNode;
            back->next = newNode;
            front = newNode;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = back = newNode;
            front->next = front->prev = front;
        } else {
            newNode->next = front;
            newNode->prev = back;
            back->next = newNode;
            front->prev = newNode;
            back = newNode;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        if (size == 1) {
            delete front;
            front = back = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            back->next = front;
            front->prev = back;
            delete temp;
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        if (size == 1) {
            delete back;
            front = back = nullptr;
        } else {
            Node* temp = back;
            back = back->prev;
            back->next = front;
            front->prev = back;
            delete temp;
        }
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return front->val;
    }

    int getRear() {
        if (isEmpty()) return -1;
        return back->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
