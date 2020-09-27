#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //int arr[6]={1,9,3,4,5,6};
    //int(*t)[6]=&arr;
    //int(*t)[6]=arr;
    //&arr数组首地址
    //arr数组元素首地址
    
    char *str[6] = {"aaa", "bbb", "ccc", "ddd", "eee", "fff"};
    for (int i = 0; i < 6; i++)
    {
        cout << str[i] << endl;
    }
    cout<<"-------------------"<<endl;
    int arr[2][3]={{1,2,3},{4,5,6}};
    int (*p)[3]=arr;
    cout<<**p<<endl;
    p++;
    cout<<**p<<endl;
    return 0;
}