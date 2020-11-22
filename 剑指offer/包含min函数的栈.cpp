class Solution {
public:
    void push(int value) {
        stackdate.push(value);
        if(stackmin.empty())
            stackmin.push(value);
        else if(value<=stackmin.top())
            stackmin.push(value);
        else if(value>stackmin.top())
            stackmin.push(stackmin.top());
    }
    void pop() {
        stackdate.pop();
        stackmin.pop();
    }
    int top() {
        return stackdate.top();
    }
    int min() {
        return stackmin.top();
    }
private:
    stack<int> stackdate;
    stack<int> stackmin;
};