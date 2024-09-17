struct Node{
    pair<int,int> p;
    Node *next;
    Node(int x){
        p.first=x;
        p.second=INT_MAX;
        next=NULL;
    }
};
class MinStack {
public:
    Node* topi;
    MinStack() {
      topi=NULL;  
    }
    
    void push(int val) {
        if(topi==nullptr){
            topi=new Node(val);
            topi->p.second=val;}
        else{
            Node *temp=new Node(val);
            temp->next=topi;
            temp->p.second=min(val,topi->p.second);
            topi=temp;
        }
    }
    
    void pop() {
        topi=topi->next;
    }
    
    int top() {
        return topi->p.first;
    }
    
    int getMin() {
        return topi->p.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */