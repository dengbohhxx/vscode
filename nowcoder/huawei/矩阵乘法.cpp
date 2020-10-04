#include <iostream>
#include <vector>
using namespace std;
void print(vector<vector<int>> vec)
{
    int m = vec.size();
    int n = vec[0].size();
    for (int i = 0; i < m; i++)
    {
        cout<<vec[i][0];
        for (int j = 1; j < n; j++)
        {
            cout <<" "<< vec[i][j] ;
        }
        cout << endl;
    }
}
int compute(vector<vector<int>> vec1, vector<vector<int>> vec2, int m, int n)
{
    int sum = 0;
    int m1 = vec1.size();
    int n1 = vec1[0].size();
    int m2 = vec2[0].size();
    for (int i = 0; i < n1; i++)
    {
        sum += vec1[m][i] * vec2[i][n];
    }
    return sum;
}
int main()
{
    int m1, n1, m2;
    while (cin >> m1 >> n1 >> m2)
    {
        int num;
        vector<vector<int>> vec1(m1, vector<int>(n1));
        vector<vector<int>> vec2(n1, vector<int>(m2));
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                cin >> num;
                vec1[i][j] = num;
            }
        }
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                cin >> num;
                vec2[i][j] = num;
            }
        }
        //cout<<"***********************"<<endl;
        //print(vec1);
        //print(vec2);
        vector<vector<int>> vec3(m1, vector<int>(m2));
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                vec3[i][j] = compute(vec1, vec2, i, j);
            }
        }
        print(vec3);
    }

    return 0;
}