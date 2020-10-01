class StackReverse {
public:
    int get(stack<int> &sta)
    {
        int result=sta.top();
        sta.pop();
        if(sta.empty())
            return result;
        else
        {
            int last=get(sta);
            sta.push(result);
            return last;
        }
    }
    stack<int> reverse(stack<int> &sta)
    {
        if(sta.empty())
           return sta;
        else
        {
            int i=get(sta);
            reverse(sta);
            sta.push(i);
            return sta;
        }
        
        
    }
    /*
        void reverse(stack<int> &sta)
    {
        if(sta.empty())
           return ;
        else
        {
            int i=get(sta);
            reverse(sta);
            sta.push(i);
        }
    }
    */
    vector<int> reverseStack(vector<int> A, int n) {
        // write code here
        stack<int> stk1;
        for(int i=n-1;i>=0;i--)
        {
            stk1.push(A[i]);
        }
        stk1=reverse(stk1);
        A.clear();
        for(int i=0;i<n;i++)
        {
            A.push_back(stk1.top());
            stk1.pop();
        }
        return A;
    }
};