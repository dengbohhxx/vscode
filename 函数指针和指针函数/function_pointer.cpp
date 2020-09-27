#include <iostream>
using namespace std;
class Date
{
    public:
    Date(int x, int y) : a(x), b(y) {}
    void print()
    {
        cout << "a:" << this->a << ";"<<  "b:"<< this->b << endl;
    }
private:
    int a;
    int b;
};
Date * func(int x,int y)
{
    Date * p=new Date(x,y);
    return p;
}
void swap_add(int &a,int &b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}
int main()
{
    //函数指针
    Date * pdate=func(5,10);
    cout<<"打印：  ";
    pdate->print();
    //函数指针
    void( *p)(int &x,int& y);
    p=&swap_add;
    //p=swap_add
    int a=10;
    int b=20;
    (*p)(a,b);
    cout<<"a:"<<a<<" b:"<<b;
    return 0;

}