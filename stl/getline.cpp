#include <iostream>
#include <vector>
#include <string>
using namespace std;
void print(vector<string> vec)
{
    for (vector<string>::iterator iter = vec.begin(); iter != vec.end(); iter++)
    {
        cout << *iter << endl;;
    }
    cout << endl;
    cout << "++++++" << endl;
}
int main()
{
    string s;
    vector<string> vec;
    /*
    while (cin >> s)
    {
        vec.push_back(s);
    }
    print(vec);
    vec.clear();
    */
   /*
    while(getline(cin,s))
    {
        vec.push_back(s);
    }
    print(vec);
    */
   char a[100]={};
   while(cin.getline(a,100))
   {
       string  b(a,a+100);
       vec.push_back(b);
   }
   print(vec);
    return 0;
}