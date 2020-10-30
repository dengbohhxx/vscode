#include<iostream>
#include<vector>
using namespace std;
int month[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int y,m,d;
    while(cin>>y>>m>>d)
    {
        if((y%4==0&&y%100!=0)||(y%100==0&&y%400==0))
        {
            month[2]=29;
        }
        if(m>12||m<1||d>month[m]||d<=0)
            return -1;
        int sum=0;
        for(int i=1;i<m;i++)
        {
            sum+=month[i];
        }
        sum+=d;
        cout<<sum<<endl;
    }
    return 0;
}