class CustomStack {
public:
deque<int> dq;
int count;
int max;
    CustomStack(int maxSize) {
        count=0;
        max=maxSize;
    }
    
    void push(int x) {
        if(count<max)
        {
            dq.push_front(x);
            count++;
        }
        
    }
    
    int pop() {
        int a;
        if(count>0)
        {
            a=dq.front();
            dq.pop_front();
            count--;
        }
        else
        {
            a=-1;
        }
        return a;
        
    }
    
    void increment(int k, int val) {
        stack<int> st;
        while(k!=0 && !dq.empty())
        {
            int a=dq.back();
            dq.pop_back();
            a=a+val;
            st.push(a);
            k--;
        }
        while(!st.empty())
        {
            dq.push_back(st.top());
            st.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */