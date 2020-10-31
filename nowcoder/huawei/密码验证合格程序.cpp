#include<iostream>
#include<string>
using namespace std;
bool no_big_than_2_substr(string str)
{
    bool res=true;
    for(int i=0;i<str.size();i++)
    {
        string s=str.substr(i,3);
        if(str.find(s,i+3)!=string::npos)
        {
            res=false;
            break;
        }
    }
    return res;
}
int main()
{
    string str;
    while(cin>>str)
    {
        bool up=false;
        bool low=false;
        bool number=false;
        bool syb=false;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>='a'&&str[i]<='z')
                low=true;
            else if(str[i]>='A'&&str[i]<='Z')
                up=true;
            else if(str[i]>='0'&&str[i]<='9')
                number=true;
            else
                syb=true;
        }
        int k=0;
        if(low==true)
            k++;
        if(up==true)
            k++;
        if(number==true)
            k++;
        if(syb==true)
            k++;
        bool flag=no_big_than_2_substr(str);
        if(k>=3&&str.size()>8&&flag)
        {
            cout<<"OK"<<endl;
        }
        else
        {
            cout<<"NG"<<endl;
        }
        
    }
    return 0;
}