class Solution {
public:
    string removeDuplicates(string S) {
        int n=S.size();
        if(n==0)    
            return S;
        stack<char> stk;
        for(int i=n-1;i>=0;i--)
        {
            if(stk.empty())
            {
                stk.push(S[i]);
            }
            else if(stk.top()==S[i])
            {
                stk.pop();
            }
            else
            {
                stk.push(S[i]);
            }
        }
        string s;
        while(!stk.empty())
        {
            s+=stk.top();
            stk.pop();
        }
        return s;
    }
};