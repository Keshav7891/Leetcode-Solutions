class MinStack {
public:
    stack<int>mins;
    stack<int>s;
    
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(mins.empty()==true)
        {
            mins.push(val);
        }
        else
        {
            mins.push(min(mins.top(),val));
        }
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
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