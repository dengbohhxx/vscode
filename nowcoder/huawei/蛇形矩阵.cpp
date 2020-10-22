#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 0;
    while (cin >> n)
    {
        vector<vector<int>> vec(n);
        int start = 1;
        for (int i = 0; i < n; i++)
        {
            vec[i].push_back(start);
            start = start + i + 1;
        }
        int m = n;
        int current = 2;
        for (int i = 0; i < n; i++)
        {
            int temp = vec[i][0];

            for (int j = 1; j < m; j++)
            {
                temp = temp + current + j - 1;
                vec[i].push_back(temp);
            }
            current++;
            m--;
        }
        for (int i = 0; i < n; i++)
        {
            for (vector<int>::iterator iter = vec[i].begin(); iter != vec[i].end(); iter++)
            {
                cout << *iter << " ";
            }
            cout << endl;
        }
    }
    return 0;
}