#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n=0;
    while(cin>>n)
    {
        int k=0;
        while(n)
        {
            if(n&1!=0)
            {
                k++;
            }
            n=n>>1;
        }
        cout<<k<<endl;
    }
    return 0;
}