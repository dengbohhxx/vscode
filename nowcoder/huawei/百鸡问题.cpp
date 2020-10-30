#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int i,j,k;
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<=33;j++)
            {
                k=100-i-j;
                if((i*5+j*3+k/3==100)&&k%3==0)
                    cout<<i<<" "<<j<<" "<<k<<" "<<endl;
            }
        }
    }
    return 0;
}