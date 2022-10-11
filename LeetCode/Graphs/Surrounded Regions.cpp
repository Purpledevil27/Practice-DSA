// https://leetcode.com/problems/surrounded-regions/

/*Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.

Example 2:

Input: board = [["X"]]
Output: [["X"]]

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(vector<vector<char>> &board, int i, int j, int const &m, int const &n)
    {
        if (i >= m || j >= n || i < 0 || j < 0 || board[i][j] == 'X' || board[i][j] == 'A')
        {
            return;
        }
        board[i][j] = 'A';
        dfs(board, i + 1, j, m, n);
        dfs(board, i, j + 1, m, n);
        dfs(board, i, j - 1, m, n);
        dfs(board, i - 1, j, m, n);
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == m - 1 || j == n - 1 || j == 0 && board[i][j] == 'O')
                    dfs(board, i, j, m, n);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'A')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};