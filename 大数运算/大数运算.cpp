#include <iostream>
#include <vector>
#include <string>
using namespace std;
class bignum
{
public:
    vector<char> vec;
    int len;
    bignum(string str)
    {
        int size = str.size();
        for (int i = 0; i < size; i++)
        {
            vec.push_back(str[i] - '0');
        }
        len = size;
    }
    bignum(){}
    void print()
    {
        for(int i=0;i<this->len;i++)
        {
            cout<<this->vec[i];
        }
        cout<<endl;
    }
};

bignum reverse(bignum x)
{
    bignum a;
    a.len=x.len;
    for(int i=0;i<x.len;i++)
    {
        a.vec.push_back(x.vec[x.len-1-i]);
    }
    return a;
}
bignum fill0(bignum x, int len)
{
    if(len==0)
    return x;
    if(len>0)
    {
        for(int i=0;i<len;i++)
        {
            x.vec.push_back(0);
        }
        return x;
    }
}

bignum sum(bignum a, bignum b)
{
    a=reverse(a);
    b=reverse(b);
    if(a.len>b.len)
    {
        bignum b=fill0(b,a.len-b.len);
    }
    if(a.len<b.len)
    {
        bignum a=fill0(a,b.len-a.len);
    }
    int k=0;
    bignum c;
    for(int i=0;i<a.len;i++)
    {
        int n=a.vec[i]+b.vec[i]+k;
        c.vec.push_back(n%10);
        k=k/10;
    }
    c.len=a.len;
    if(k!=0)
    {
        c.vec.push_back(1);
        c.len++;
    }
    c=reverse(c);
    return c;
}
int main()
{
    string str1="123";
    string str2="111";
    bignum num1(str1);
    bignum num2(str2);
    bignum num3=sum(num1,num2);
    num3.print();
    return 0;
}