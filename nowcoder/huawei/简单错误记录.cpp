#include<iostream>
#include<string>
#include<vector>
#include<deque>
using namespace std;
struct item
{
    string str;
    int line;
};
struct itemres
{
    string str;
    int line;
    int num;
};
string name(string str)
{
    int n=str.size();
    int k=0;
    for(int i=n-1;i>=0;i--)
    {
        if(str[i]== '\\')
        {
            k=i;
            break;
        }
    }
    string s=str.substr(k+1);
    return s;
}
string name16(string s)
{
    int size=s.size();
    if(size<=16)
        return s;
    else
    {
        string s1=s.substr(size-16);
        return s1;
    }
}
void push (deque<itemres> &res,itemres is)
{
    int n=res.size();
    if(n==0)
        res.push_back(is);
    else
    {
        int i=0;
        for( i=0;i<n;i++)
        {
            if(res[i].str==is.str&&res[i].line==is.line)
            {
                res[i].num++;
                break;
            }
        }
        if(i==n)
        {
            res.push_back(is);
        }
    }
}
int main()
{
    string str;
    int num;
    vector<item> vec;
    while(cin>>str>>num)
    {
        item items;
        items.str=str;
        items.line=num;
        vec.push_back(items);
    }
    deque <itemres> res;
    for(int i=0;i<vec.size();i++)
    {
        itemres is;
        is.str=name(vec[i].str);
        is.line=vec[i].line;
        is.num=1;
        push(res,is);
    }
    int size=res.size();
    if(size<=8)
    {
        for(int i=0;i<res.size();i++)
        {
            res[i].str=name16(res[i].str);
        }
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i].str<<" "<<res[i].line<<" "<<res[i].num<<endl;
        }
    }
    else
    {
        deque <itemres> res1(res.end()-8,res.end());
        for(int i=0;i<res1.size();i++)
        {
            res1[i].str=name16(res1[i].str);
        }
        for(int i=0;i<res1.size();i++)
        {
            cout<<res1[i].str<<" "<<res1[i].line<<" "<<res1[i].num<<endl;
        }
    }
    return 0;
}