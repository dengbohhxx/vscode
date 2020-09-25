#include <iostream>
#include <deque>
#include<algorithm>
using namespace std;
int main()
{
    deque<int> a;
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    

    a.push_front(2);
    a.push_front(1);
    a.push_front(0);

    for(size_t i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<"****************"<<endl;
    a.pop_back();
    a.pop_front();

    for(deque<int>::iterator iter=a.begin();iter!=a.end();iter++)
    {
        cout<<*iter<<endl;
    }
    cout<<"***************"<<endl;

    for(deque<int>::iterator iter=a.begin();iter!=a.end();iter++)
    {
        size_t idx=distance(a.begin(),iter);
        cout<<a[idx]<<endl;
    }
     cout<<"***************"<<endl;
    a.clear();
    bool b=a.empty();
    cout<<b<<endl;

    return 0;
}