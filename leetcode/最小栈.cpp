class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(stkmin.empty())
        {
            stkmin.push(x);
        }
        else
        {
            stkmin.push(min(stkmin.top(),x));
        }
        stkstore.push(x);
    }
    
    void pop() {
        stkstore.pop();
        stkmin.pop();
    }
    
    int top() {
        return stkstore.top();
    }
    
    int getMin() {
        return stkmin.top();
    }
private:
    stack<int> stkmin;
    stack<int> stkstore;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */