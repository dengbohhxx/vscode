class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int solve(string s) {
        // write code here
        if(s.empty())
            return -1;
        changes(s);
        for(int i=0;i<s.size();i++)
        {
            
            if(s[i]<='9'&&s[i]>='0')
            {
                int j=i;
                int temp=0;//临时存储数值
                while(s[j]<='9'&&s[j]>='0'&&j<s.size())
                {
                    temp=temp*10+s[j]-'0';
                    j++;
                }
                num.push(temp);
                i=j-1;
            }
            else
            {
                if(s[i]=='('||sig.empty())//符号栈为空或者s[i]='('直接push
                {
                    sig.push(s[i]);
                }
                else 
                {
                    if(s[i]=='+'||s[i]=='-')
                    {
                        while(!sig.empty()&&sig.top()!='(')
                            calc();
                        sig.push(s[i]);
                    }
                    if(s[i]=='*'||s[i]=='/')
                    {
                        while(!sig.empty()&&(sig.top()=='*'||sig.top()=='/'))
                            calc();
                        sig.push(s[i]);
                    }
                    if(s[i]==')')
                    {
                        while(!sig.empty()&&sig.top()!='(')
                            calc();
                        sig.pop();
                    }
                }
            }
        }
        while(!sig.empty())
            calc();
        int res=num.top();
        return res;
    }
    private:
    stack<int> num;
    stack<char> sig;
    int com(int a,int b,char c)//符号运算
    {
        switch(c)
        {
            case '+':return a+b;
            case '-':return a-b;
            case '*':return a*b;
            case '/':if(b!=0) return a/b;
        }
        return -1;
    }
    void calc()//计算
    {
        int b=num.top();
        num.pop();
        int a=num.top();
        num.pop();
        char c=sig.top();
        sig.pop();
        num.push(com(a,b,c));
    }
    void changes(string s)//负号处理，在负号前加0
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]='-')
            {
                if(i==0)
                    s.insert(i,"0");
                if(i>0&&s[i-1]=='(')
                    s.insert(i,"0");
            }
        }
        return ;
    }
};