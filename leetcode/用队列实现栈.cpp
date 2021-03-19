class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que2.push(x);
        while(!que1.empty())
        {
            que2.push(que1.front());
            que1.pop();
        }
        swap(que1,que2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res=que1.front();
        que1.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return que1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty();
    }
private:
    queue<int> que1;
    queue<int> que2;

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */