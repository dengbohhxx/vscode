#include<iostream>
#include<queue>
#include<deque>
#include<algorithm>
using namespace std;
int main()
{
    //最大优先级队列
    priority_queue<int,vector<int> > pq1;
    priority_queue<int,deque<int> >pq2;
    //默认是vector
    priority_queue<int> pq;
    pq.push(5);
    pq.push(50);
    pq.push(6);
    pq.push(7);
    cout<<pq.top()<<endl;
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    cout<<"**********************"<<endl;

    priority_queue<int,vector<int>,greater<int> >  pq3;
    pq3.push(5);
    pq3.push(50);
    pq3.push(-6);
    pq3.push(7);
    cout<<pq3.top()<<endl;
    while(!pq3.empty())
    {
        cout<<pq3.top()<<" ";
        pq3.pop();
    }
    cout<<endl;
    cout<<"**********************"<<endl;


    return 0;


}