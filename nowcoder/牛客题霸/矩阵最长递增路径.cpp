#include <iostream>
#include <vector>
using namespace std;
void backtrace(vector<vector<int>> &mat, vector<vector<int>> dirs, int maxlen, int i, int j, int m, int n, vector<int> &res)
{
    int num = mat[i][j];
    for (int k= 0; k < 4; k++)
    {
        int newi = i + dirs[k][0];
        int newj = j + dirs[k][1];
        if (newi >= 0 && newi < m && newj >= 0 && newj < n && mat[newi][newj] > num)
        {
            backtrace(mat, dirs, maxlen + 1, newi, newj, m, n, res);
        }
    }
    res[0] = max(res[0], maxlen);
}
int solve(vector<vector<int>> &matrix)
{
    // write code here
    int m = matrix.size();
    int n = matrix[0].size();
    if (m == 0 || n == 0)
        return 0;
    int maxlen = 1;
    vector<vector<int>> dirs(4, vector<int>(2, 0));
    dirs[0][0] = -1;
    dirs[0][1] = 0;
    dirs[1][0] = 1;
    dirs[1][1] = 0;
    dirs[2][0] = 0;
    dirs[2][1] = -1;
    dirs[3][0] = 0;
    dirs[3][1] = 1;
    vector<int> res(1, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            backtrace(matrix, dirs, maxlen, i, j, m, n, res);
        }
    }
    return res[0];
}
int main()
{
    int num = 0;
    vector<vector<int>> vec(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> vec[i][j];
        }
    }
    int a = solve(vec);
    cout << a << endl;
}