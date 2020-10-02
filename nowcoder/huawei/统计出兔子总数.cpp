#include<iostream>
#include<vector>
#include<string>
using namespace std;
int sum_rab(int n)
{
    if(n==1||n==2)
        return 1;
    else
    {
        return sum_rab(n-1)+sum_rab(n-2);
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<sum_rab(n)<<endl;
    }
    return 0;
}