#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void swap_add(int &a,int&b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}
int main()
{
    int a = 10;
    int b = 20;
    cout << "指针:" << endl;
    swap(&a, &b);
    cout << "a:" << a << ",b:" << b << endl;
    cout << "引用:" << endl;
    swap(a, b);
    cout << "a:" << a << ",b:" << b << endl;
    cout << "相加交换:" << endl;
    swap_add(a, b);
    cout << "a:" << a << ",b:" << b << endl;
    return 0;
}