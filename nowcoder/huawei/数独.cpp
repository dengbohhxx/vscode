#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<vector<char>> &board, int x, int y, char ch)
{
    for (int i = 0; i < 9; ++i)
    {
        if (board[x][i] == ch)
            return false;
        if (board[i][y] == ch)
            return false;
        if (board[(x / 3) * 3 + i / 3][(y / 3) * 3 + i % 3] == ch)
            return false;
    }
    return true;
}
bool dfs(vector<vector<char>> &board, int x, int y)
{
    if (x == 9)
    {
        return true;
    }
    if (y == 9)
    {
        return dfs(board, x + 1, 0);
    } // 跳转到下一行
    if (board[x][y] != '0')
    {
        return dfs(board, x, y + 1);
    }
    for (char c = '1'; c <= '9'; ++c)
    {
        if (!isValid(board, x, y, c))
            continue;
        board[x][y] = c;
        if (dfs(board, x, y + 1))
            return true;
        board[x][y] = '0';
    }
    return false;
}
void Sudoku(vector<vector<char>> &board)
{
    dfs(board, 0, 0);
}
int main()
{
    char num = 0;
    vector<vector<char>> vec(9, vector<char>(9, 0));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> vec[i][j];
        }
    }
    Sudoku(vec);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << vec[i][8];
        cout << endl;
    }
    return 0;
}