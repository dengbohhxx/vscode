#include<iostream>
#include<deque>
#include<list>
#include<queue>
using namespace std;
int main()
{
    queue<int,deque<int> > a;
    queue<int ,list<int> > b;
    //wrong
    //queue<int,vector<int> > c;
    queue<int > c;
    for(int i=0;i<10;i++)
    {
        c.push(i);
    }
    cout<<c.front()<<endl;
    cout<<c.back()<<endl;
    cout<<c.size()<<endl;

    c.pop();
    cout<<c.front()<<endl;





    return 0;
}