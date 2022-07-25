// https://leetcode.com/problems/sudoku-solver/

/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Example 1:

Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.s
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isSafe(int const &row, int const &col, vector<vector<char>> &board, int const &num)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == num + '0' || board[i][col] == num + '0')
                return false;
        }

        int row_factor = row - (row % 3);
        int col_factor = col - (col % 3);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i + row_factor][j + col_factor] == num + '0')
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        int row = -1, col = -1;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    row = i;
                    col = j;
                }
            }
        }
        if (row == -1 && col == -1)
            return true;
        for (int i = 1; i <= 9; i++)
        {
            if (isSafe(row, col, board, i))
            {
                board[row][col] = i + '0';
                if (solve(board))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};