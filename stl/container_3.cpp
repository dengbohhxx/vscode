#include <iostream>
#include <list>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;
void print(vector<string>);
int main()
{
    vector<string> vec;
    vec.push_back("ali");
    vec.push_back("baidu");
    vec.push_back("tencent");
    vec.push_back("jingdong");
    print(vec);
    //vec.erase(vec.begin(),vec.begin()+2);
    //vec.erase(vec.begin());
    vector<string>::iterator iter=find(vec.begin(),vec.end(),"baidu");
    if(iter!=vec.end())
        vec.erase(iter);
    else
    {
        cout<<"don't find it"<<endl;
    }
    
    print(vec);
    return 0;
}
void print(vector<string> a)
{
    for (vector<string>::iterator iter = a.begin(); iter != a.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    cout << "++++++++++++" << endl;
}