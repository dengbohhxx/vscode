#include<iostream>
using namespace std;
int digui(int m,int n)
{
    if(m==0||n==1)
        return 1;
    else if(m<n)
        return digui(m,m);
     else
         return digui(m-n,n)+digui(m,n-1);
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