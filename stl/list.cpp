#include<iostream>
#include<list>
#include<vector>
using namespace std;
int main()
{
    list<int>  a;
    vector<int> b(10,2);
    a.push_front(3);
    a.push_front(200);
    a.push_front(1);
    a.push_front(0);
    a.push_back(4);
    a.push_back(5);
    //a.insert(a.begin(),5,10);
    //a.insert(a.begin(),b.begin(),b.begin()+2);
    a.insert(a.end(),6);
    a.insert(a.end(),7);
    for(list<int>::iterator iter=a.begin();iter!=a.end();iter++)
        cout<<*iter<<endl;
    cout<<"*********************"<<endl;
    list<int>::iterator iter=a.begin();
    iter=++iter;
    a.erase(iter);
    for(list<int>::iterator iter=a.begin();iter!=a.end();iter++)
        cout<<*iter<<endl;
    cout<<"*********************"<<endl;
    a.reverse();
    for(list<int>::iterator iter=a.begin();iter!=a.end();iter++)
        cout<<*iter<<endl;
    cout<<"*********************"<<endl;
    a.sort();
    for(list<int>::iterator iter=a.begin();iter!=a.end();iter++)
        cout<<*iter<<endl;
    cout<<"*********************"<<endl;
    return 0;
}