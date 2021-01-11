#include<iostream>
#include<string>
#include<string>
using namespace std;
bool isupper(char c)
{
    if(c>='A'&&c<='Z')
        return true;
    return false;
}
string jiami(string s)
{
    string str;
    int n=s.size();
    if(n==0)
        return str;
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(s[i]=='9')
                str+='0';
            else
            {
                str=str+to_string(s[i]-'0'+1);
            }
        }
        else
        {
            if(isupper(s[i])==true)
            {
                if(s[i]=='Z')
                {
                    str+='a';
                }
                else
                {
                    str+=(s[i]-'A'+1)+'a';
                }
            }
            else
            {
                 if(s[i]=='z')
                {
                    str+='A';
                }
                else
                {
                    str+=(s[i]-'a'+1)+'A';
                }
            }
        }
    }
    return str;
}
string jiemi(string s)
{
    string str;
    int n=s.size();
    if(n==0)
        return str;
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(s[i]=='0')
                str+='9';
            else
            {
                str=str+to_string(s[i]-'0'-1);
            }
        }
        else
        {
            if(isupper(s[i])==true)
            {
                if(s[i]=='A')
                {
                    str+='z';
                }
                else
                {
                    str+=(s[i]-'A'-1)+'a';
                }
            }
            else
            {
                 if(s[i]=='a')
                {
                    str+='Z';
                }
                else
                {
                    str+=(s[i]-'a'-1)+'A';
                }
            }
        }
    }
    return str;
}
int main()
{
    string str;
    string stred;
    while(cin>>str>>stred)
    {
        string s1=jiami(str);
        string s2=jiemi(stred);
        cout<<s1<<endl<<s2<<endl;
    }
    
    
    
    return 0;
}