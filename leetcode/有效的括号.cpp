class Solution {
public:
    char match(char c)
    {
        if(c==')')
            return '(';
        else if(c==']')
            return '[';
        return '{'; 
    }
    bool isValid(string s) {
        stack<char> left;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                left.push(s[i]);
            }
            else
            {
                if(!left.empty()&&match(s[i])==left.top())
                {
                    left.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return left.empty()?true:false;
    }
};