//
// Created by jt on 2020/9/1.
//
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char> > &board, int x, int y) {
        if (x == 9) 
        { 
            return true; 
        }
        if (y == 9)
        { 
            return dfs(board, x+1, 0);
        }  // 跳转到下一行
        if (board[x][y] != '.') 
        { 
            return dfs(board, x, y+1); 
        }
        for (char c = '1'; c <= '9'; ++c) {
            if (!isValid(board, x, y, c)) 
                continue;
            board[x][y] = c;
            if (dfs(board, x, y+1)) 
                return true;
            board[x][y] = '.';
        }
        return false;
    }

    bool isValid(vector<vector<char> > &board, int x, int y, char ch) {
        for (int i = 0; i < 9; ++i) 
        {
            if (board[x][i] == ch) 
                return false;
            if (board[i][y] == ch) 
                return false;
            if (board[(x/3)*3 + i/3][(y/3)*3 + i%3] == ch) 
                return false;
        }
        return true;
    }
};