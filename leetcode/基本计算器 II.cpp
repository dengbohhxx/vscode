class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num=0;
        char sign='+';//第一个数字前面为+
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(isdigit(c))
            {
                num=num*10+(c-'0');//处理数字
            }
            if(!isdigit(c)&&c!=' '||i==n-1)//处理符号 非数字且不是' ',或者是字符串中最后一个字符
            {
                switch(sign)
                {
                    int pre;
                    case '+': //加号就push正数
                        {
                            stk.push(num);
                            break;
                        }
                    case '-': //减号就push负数
                    {
                        stk.push(-num);
                        break;
                    }
                    case '*': //乘号就push前一个数和num乘积
                    {
                        pre=stk.top();
                        stk.pop();
                        stk.push(pre*num);
                        break;
                    }
                    case '/': //除号就push前一个数和num商
                    {
                        pre=stk.top();
                        stk.pop();
                        stk.push(pre/num);
                        break;
                    }
                }
                sign=c;//将下一个符号赋值给sign
                num=0;
            }
        }
        int res=0;
        while(!stk.empty())
        {
            res+=stk.top();
            stk.pop();
        }
        return res;
    }
};