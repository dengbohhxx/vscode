#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<list>
using namespace std;
int main()
{
    list<int> a;
    a.push_front(3);
    a.push_front(2);
    a.push_front(1);
    a.push_back(4);
    for(list<int>::iterator iter=a.begin();iter!=a.end();iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    cout<<"++++++++++++++++"<<endl;
    a.insert(a.begin(),0);
    for(list<int>::iterator iter=a.begin();iter!=a.end();iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    cout<<"++++++++++++++++"<<endl;
    a.insert(a.begin(),10,1000);
    for(list<int>::iterator iter=a.begin(); iter!=a.end(); iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    cout<<"++++++++++++++++"<<endl;
    list<int> a1;
    a1.push_front(30);
    a1.push_front(20);
    a1.push_front(10);
    a1.push_back(40);
    a.insert(a.begin(),a1.begin(),a1.end());
    for(list<int>::iterator iter=a.begin();iter!=a.end();iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    cout<<"++++++++++++++++"<<endl;

    return 0;
}