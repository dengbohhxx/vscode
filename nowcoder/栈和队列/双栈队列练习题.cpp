class TwoStack {
public:
    vector<int> twoStack(vector<int> ope, int n) 
    {
        // write code here
        vector<int> outvec;
        for (int i = 0; i < n; i++)
        {
            if (ope[i]>0)
            {
                stackpush.push(ope[i]);
            }
            else if (ope[i] == 0)
            {
                if (stackpop.size() == 0)
                {
                    int tempPushsize = stackpush.size();
                    for (int j = 0; j < tempPushsize; j++)
                    {
                        stackpop.push(stackpush.top()); //将push栈中的栈顶元素入栈到pop栈
                        stackpush.pop();                            //弹出push的栈顶元素
                    }
                    outvec.push_back(stackpop.top());
                    stackpop.pop();
                }
                else if(stackpop.size() > 0 ) //pop栈还有元素
                {
                    outvec.push_back(stackpop.top()); //从pop栈中取栈顶并放入数组
                    stackpop.pop();
                }
            }
        }
        return outvec;
    }
private:
    stack <int> stackpush;
    stack<int> stackpop;
};