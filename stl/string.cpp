#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s("annabella");
    string s1("bella");
    string::size_type pos1=s.find("bella");
    if(pos1!=string::npos)
    {
        cout<<" find it"<<endl;
    }
    else
    {
        cout<<"not find!!!"<<endl;
    }
    string name("r2d3dfsdfsdfsd55665");
    string  num("0123456789");
    string::size_type pos=0;
    while((pos=name.find_first_of(num,pos))!=string::npos)
    {
        cout<<name[pos]<<endl;
        pos++;
    }
    return 0;
}