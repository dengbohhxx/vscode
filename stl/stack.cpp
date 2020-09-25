
#include<iostream>
#include<stack>
#include<vector>
#include<list>
#include<deque>
using namespace std;
int main()
{
    stack<int,vector<int> > a;
    stack<int,list<int> > b;
    stack<int ,deque<int> > c;
    stack<int> d;
    d.push(1);
    d.push(2);
    d.push(3);

    int x=d.top();
    cout<<x<<endl;
    d.pop();
    x=d.top();
    cout<<x<<endl;
    int size=d.size();
    cout<<size<<endl;
    cout<<d.empty()<<endl;
    cout<<"----------------------------"<<endl;
    while(d.empty()==false)
    {
        x=d.top();
        cout<<x<<endl;
        d.pop();
    }

    return 0;
}