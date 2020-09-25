#include <iostream>
using namespace std;
//递归
int   Fibonacci_rec(int n)
{
    if (n==0)
        return 0;
    else if(n==1)
        return 1;
    else
    {
        return   Fibonacci_rec(n-1)+ Fibonacci_rec(n-2);
    }
}
//循环
int  Fibonacci_for(int n)
{
    int  res=0;
    if(n==0)
        {
            res=0;
            return res;
        }
    if(n==1)
    {
        res=1;
        return res;
    }
    int first=0;
    int second=1;
    for (int i=2;i<=n;i++)
    {
        res=first+second;
        first=second;
        second=res;
    }
    return  res;
}


int main()
{
  int num=0;
  cin>>num;
  
  cout<<"递归:"<<Fibonacci_rec(num)<<endl;
  cout<<"循环:"<<Fibonacci_for(num)<<endl;

    return 0;
}