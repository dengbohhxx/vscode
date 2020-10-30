#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int num=0;
    while(cin>>num)
    {
        int mid=num*num*num/num;
        int n=0;
        int start=0;
        if(mid%2==0)
        {
            n=num/2;
            start=mid-1-(n-1)*2;
        }
        else
        {
            n=(num-1)/2;
            start=mid-n*2;
        }
        for(int i=0;i<num-1;i++)
        {
            cout<<start<<"+";
            start=start+2;
        }
        cout<<start<<endl;
    }
    
    
    
    return 0;
}