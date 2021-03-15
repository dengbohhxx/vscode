class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
            if(stkpush.empty())
            {
                peekelement=x;
            }
             stkpush.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stkpop.empty())
        {
            int tempsize=stkpush.size();
            for(int i=0;i<tempsize;i++)
            {
                stkpop.push(stkpush.top());
                stkpush.pop();
            }
            int temp=stkpop.top();
            stkpop.pop();
            if(!stkpop.empty())
                peekelement=stkpop.top();
            return temp;
        }
        int temp=stkpop.top();
        stkpop.pop();
        if(!stkpop.empty())
                peekelement=stkpop.top();
        return temp;

    }
    
    /** Get the front element. */
    int peek() {
        return peekelement;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stkpush.empty()&&stkpop.empty();
    }
private:
    stack<int> stkpush;
        stack<int> stkpop;
        int peekelement;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */