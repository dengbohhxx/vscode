#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int row;
    int column;
    cin >> row;
    cin >> column;
    
    vector<vector<int> > vec(row,vector<int>(column));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cin>>vec[i][j];
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int **p = new int *[row];
    for (int i = 0; i < row; i++)
        p[i] = new int[column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> p[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}