class Solution {
public:
    void push(int value) {
        if(stackmin.empty())
        {
            stackdata.push(value);
            stackmin.push(value);
        }
        else
        {
            if(value<stackmin.top())
            {
                stackdata.push(value);
                stackmin.push(value);
            }
            else
            {
                stackdata.push(value);
                stackmin.push(stackmin.top());
            }
        }
    }
    void pop() {
        if(!stackdata.empty())
        {
            stackdata.pop();
            stackmin.pop();
        }
    }
    int top() {
        return stackdata.top();
    }
    int min() {
        return stackmin.top();
    }
private:
    stack<int> stackdata;
    stack<int> stackmin;
};