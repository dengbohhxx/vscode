#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int a,b;
    char ch;
    while(cin>>a>>ch>>b)
    {
        while(a!=1)
        {
            int q=b/a;
            int r=b%a;
            cout<<"1"<<"/"<<q+1<<"+";
            a=a-r;
            b=b*(1+q);
            if (b%a == 0)
            {
              b = b / a;
              a = 1;
            }
        }
        cout<<a<<"/"<<b<<endl;
    }
    return 0;
}