#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string str;
    int num=0;
    while(cin>>str>>num)
    {
        int temp=0;
        string s;
        for(int i=0;i<=str.size()-1-num+1;i++)
        {
            int k=0;
            for(int j=i;j<i+num;j++)
            {
                if(str[j]=='C'||str[j]=='G')
                {
                    k++;
                }
            }
            if(k>temp)
            {
                s=str.substr(i,num);
                temp=k;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}