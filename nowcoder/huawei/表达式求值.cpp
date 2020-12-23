#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int prio(string s)
{
    int priority = 0;
    if (s == "*" || s == "/")
        priority = 2;
    if (s == "+" || s == "-")
        priority = 1;
    if (s == "(")
        priority = 0;
    return priority;
}
vector<string> trans(string s1)
{
    vector<string> s;
    for (int i = 0; i < s1.size(); i++)
    {
        string ss(1, s1[i]);
        s.push_back(ss);
    }
    stack<string> sta;
    vector<string> str;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= "0" && s[i] <= "9")
        {
            int j = i;
            string s2;
            while (s[j] >= "0" && s[j] <= "9" && j < s.size())
            {
                s2 += s[j];
                j++;
            }
            str.push_back(s2);
            i = j - 1;
        }
        else
        {
            if (sta.empty() || s[i] == "(")
                sta.push(s[i]);
            else if (s[i] == ")")
            {
                while (sta.top() != "(")
                {
                    str.push_back(sta.top());
                    sta.pop();
                }
                sta.pop();
            }
            else
            {
                while (prio(s[i]) <= prio(sta.top()))
                {
                    str.push_back(sta.top());
                    sta.pop();
                    if (sta.empty())
                        break;
                }
                sta.push(s[i]);
            }
        }
    }
    while (!sta.empty()) //将栈中元素清空
    {
        str.push_back(sta.top());
        sta.pop();
    }
    return str;
}
int evalrpn(vector<string> s) //逆波兰表达式求值
{
    stack<int> sta;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/")
        {
            int num1 = sta.top();
            sta.pop();
            int num2 = sta.top();
            sta.pop();
            if (s[i] == "+")
                sta.push(num2 + num1);
            if (s[i] == "-")
                sta.push(num2 - num1);
            if (s[i] == "*")
                sta.push(num2 * num1);
            if (s[i] == "/")
                sta.push(num2 / num1);
        }
        else
        {
            sta.push(stoi(s[i]));
        }
    }
    int res = sta.top();
    sta.pop();
    return res;
}
void change(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-')
        {
            if (i == 0)
                s.insert(i, "0");
            if (i > 0 && s[i - 1] == '(')
                s.insert(i, "0");
        }
    }
    return ;
}
int solve(string s)
{
    // write code here
    change(s);
    auto str = trans(s);
    return evalrpn(str);
}
int main()
{
    string str;
    while (cin >> str)
    {
        int a = solve(str);
        cout << a << endl;
    }
    return 0;
}