#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;
int main()
{
    vector<int>::size_type a1;
    vector<int>::iterator a2;
    vector<int>::const_iterator a3;
    vector<int>::reverse_iterator a4;
    vector<int>::const_reverse_iterator a5;
    vector<int>::difference_type a6;
    //泛型
    //vector<int>::value_type a7;
    //vector<int>::reference a8;
    //vector<int>::const_reference a9;
    //list和deque类似
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(100);

    for(vector<int>::size_type  i=0;i<vec.size();i++)
        {
            cout<<vec[i]<<endl;
        }
    const vector<int> a(vec);
    //a.push_back(1);
    for(vector<int>::const_iterator iter=a.begin();iter!=a.end();iter++)
    {
        cout<<*iter<<endl;
    }
    cout<<"**************"<<endl;
    for(vector<int>::reverse_iterator iter = vec.rbegin();iter !=vec.rend();iter++)
    {
        cout<<*iter<<endl;
    }

    return 0;
}