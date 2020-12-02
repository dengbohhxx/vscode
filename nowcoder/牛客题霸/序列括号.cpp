class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        stack<int> sta;
        int size=s.size();
        for(int i=0;i<size;i++)
        {
            if(sta.empty())
            {
                sta.push(s[i]);
            }
            else if(s[i]==')'&&sta.top()=='(')
            {
                sta.pop();
            }
            else if(s[i]=='}'&&sta.top()=='{')
            {
                sta.pop();
            }
            else if(s[i]==']'&&sta.top()=='[')
            {
                sta.pop();
            }
            else
            {
                sta.push(s[i]);
            }
        }
        if(sta.empty())
            return true;
        else
            return false;
    }
};