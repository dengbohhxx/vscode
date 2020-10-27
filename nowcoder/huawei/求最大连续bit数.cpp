#include<iostream>
using namespace std;
int main()
{
    int num=0;
    while(cin>>num)
    {
        int k=0;
        int res=0;
        for(int i=num;i>0;)
        {
            if((i&1)!=0)
            {
                k++;
            }
            else
            {
                k=0;
            }
            if(k>=res)
            {
                res=k;
            }
            i=i>>1;
        }
        cout<<res<<endl;
    }
    return 0;
}