#include<iostream>
using namespace std;
int digui(int m,int n)
{
 if (n>m)
        return digui(m,m);
    if (m==0)
        return 1;
    if (n==0)
        return 0;
    return digui(m,n-1)+digui(m-n,n);
}
int main()
{
    int apple,panzi;
    while(cin>>apple>>panzi)
    {
        if((apple<1||apple>10)||(panzi<1||apple>10))
            return -1;
        int k=digui(apple,panzi);
        cout<<k<<endl;
    }
    return 0;
}