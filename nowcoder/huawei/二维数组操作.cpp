#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a = 0;
    int m = 0;
    int n = 0;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int insert_row = 0;
    int insert_column = 0;
    int x3 = 0;
    int y3 = 0;
    vector<int> vec;
    while (cin >> a)
    {
        vec.push_back(a);
    }
    //矩阵大小
    m = vec[0];
    n = vec[1];
    if (m <= 9 && n <= 9)
    {
        cout << "0" << endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    
    //要交换的两个单元格
    x1 = vec[2];
    y1 = vec[3];
    x2 = vec[4];
    y2 = vec[5];
    if((x1<m&&y1<n)&&(x2<m&&y2<n))
    {
        cout<<"0"<<endl;
    }
    else
    {
    cout<<"-1"<<endl;
    }
 
    //插入行列
    insert_row=vec[6];
    insert_column=vec[7];
    if(insert_row<m&&m<9)
    {
        cout<<"0"<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    if(insert_column<n&&n<9)
    {
        cout<<"0"<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    //要获取运动轨迹的单元格
    x3=vec[8];
    y3=vec[9];
    if(x3==x1&&y3==y1)
    {
        x3=x2;
        y3=y2;
    }
    else if(x3==x2&&y3==y2)
    {
        x3=x1;
        y3=y1;
    }
    if(insert_row<x3)
    {
        x3=x3+1;
    }
    if(insert_column<y3)
    {
        y3=y3+1;
    }
    if(x3<m&&y3<n)
        cout<<"0"<<endl;
    else
    {
        cout<<"-1"<<endl;
    }
    return 0;
}