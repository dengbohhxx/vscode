#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool iszishoushu(int n)
{
    if (n==1)
        return true;
    long long num=n*n;
    string str1=to_string(n);
    string str2=to_string(num);
    int size1=str1.size();
    int size2=str2.size();
    int idx1=size1-1;
    int idx2=size2-1;
    bool res=true;
    while(size1--)
    {
        if(str1[idx1]!=str2[idx2])
        {
            res=false;
            break;
        }
        idx1--;
        idx2--;
    }
    return res;
}
int main()
{
    int n=0;
    while(cin>>n)
    {
        int k=0;
        for(int i=0;i<=n;i++)
        {
            if(iszishoushu(i))
            {
                k++;
            }
        }
        cout<<k<<endl;
        
    }
    return 0;
}}