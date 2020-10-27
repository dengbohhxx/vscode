#include<iostream>
#include<string>
using namespace std;
string unique(string str)
{
    string res="";
    if(str.empty())
        return res;
    int n=str.size();
    res+=str[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(str[i]==str[j])
                break;
            if(i==j+1)
            {
                res+=str[i];
            }
        }
    }
    return res;
}
string resconstuct(string alp,string str)
{
    int size=str.size();
    for(int i=0;i<size;i++)
    {
        int p=alp.find(str[i]);
        alp.erase(alp.begin()+p);
    }
    return str+alp;
    
}
int main()
{
    string str;
    string s;
    string c26="abcdefghijklmnopqrstuvwxyz";
    while(cin>>str>>s)
    {
        string str1=unique(str);
        string c126=resconstuct(c26,str1);
        int size=s.size();
        string s1="";
        for(int i=0;i<size;i++)
        {
            int idx=s[i]-'a';
            s1=s1+c126[idx];
        }
        cout<<s1<<endl;
    }
    return 0;
}