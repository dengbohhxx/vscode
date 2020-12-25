#include<iostream>
#include<string>
#include<vector>
using namespace std;
string strsum(string str1,string str2)
{
    int n1=str1.size();
    int n2=str2.size();
    int n=max(n1,n2)+1;
    vector<int> vec(n,0);
    int idx1=n1-1;
    int idx2=n2-1;
    for(int i=n-1;i>=0;i--)
    {
        int num1=0;
        int num2=0;
        if(idx1>=0)
        {
            num1=str1[idx1]-'0';
            idx1--;
        }
        if(idx2>=0)
        {
            num2=str2[idx2]-'0';
            idx2--;
        }
        vec[i]=num1+num2;
    }
    int carry=0;
    for(int i=n-1;i>=0;i--)
    {
        int temp=vec[i]+carry;
        vec[i]=(temp)%10;
        carry=temp/10;
    }
    int i=0;
    for(i=0;i<n;i++)
    {
        if(vec[i]!=0)
            break;
    }
    if(i==n)
        return "0";
    string s;
    for(int j=i;j<n;j++)
    {
        s+=to_string(vec[j]);
    }
     return s;   
}
int main()
{
    string str1;
    string str2;
    while(cin>>str1>>str2)
    {
        string str=strsum(str1,str2);
        cout<<str<<endl;
    }
    return 0;
}