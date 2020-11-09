/*
||和&&都遵循短路运算规则

因此:

return a||b的意思就是如果a是true则返回a,否则返回b
return a&&b的意思就是如果a是false就则返回a，否则返回b

扩展：

实质上来说，||和&&这两个运算符分别叫做短路或和短路与，因此他们都是短路运算符。

&和&&
&： 两边可以是int类型也可以是bool类型。当两边是int类型的时候则表示与运算。当时bool类型的时候，要求两侧全为真的时候才会是真，其余都是假。如果第一个是假，则不会输出，程序会继续往后判断，但是不管最后一个是true还是false，结果都是false
&&： 短路运算符。当&&左侧判断出来是false 的时候程序不会再去判断&&的右边，直接输出false。其余都一样

|和||
|： 当 | 的左边为true的时候，必须还要判断，尽管这个时候可以确定为true
||： 因此||运算符就是来解决这个问题的。当左边为true的时候不用再判断了。

#include <bits/stdc++.h>
using namespace std;
bool test1()
{
    bool a = true;
    bool b = false;
    return a||b;
}
bool test2()
{
    bool a = true;
    bool b = false;
    return a&&b;
}
int test3() 
{
    int a = 1;
    int b = 2;
    int c = 3;
    return a,b,c;
}
int main()
{
    cout << test1() << endl;//true->1
    cout << test2() << endl;//false->0
    cout << test3() << endl;//3
    return 0;
}
*/

#include<iostream>
#include<string>
using namespace std;
bool solve(string s1,string s2,int index1,int index2)
{
    if(index1==s1.size()&&index2==s2.size())
    {
        return true;
    }
    else if((index1!=s1.size()&&index2==s2.size())||(index1==s1.size()&&index2!=s2.size()))
    {
        return false;
    }
    else
    {
        if(s1[index1]==s2[index2])
            return solve(s1,s2,index1+1,index2+1);
        else
        {
            if(s1[index1]=='?')
                return solve(s1,s2,index1+1,index2+1);
            else if(s1[index1]=='*')//遇到'*'两种情况，要不就各跳过一个比较后面，要不就s2继续往后跳先不比较
                return solve(s1,s2,index1,index2+1)||solve(s1,s2,index1+1,index2+1);
            else
                return false ;
        }
    }
}
int main()
{
    string str1;
    string str2;
    while(cin>>str1>>str2)
    {
       bool res=solve(str1,str2,0,0);
       if (res==true)
           cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    return 0;
}