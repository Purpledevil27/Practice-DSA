// https://leetcode.com/problems/n-queens-ii/

/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:

Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:

Input: n = 1
Output: 1

Constraints:
1 <= n <= 9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isSafe(int const &n, vector<vector<int>> &grid, int const &row, int const &col)
    {
        for (int i = 0; i < n; i++)
        {
            if (grid[i][col] == 1)
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (grid[i][j] == 1)
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (grid[i][j] == 1)
                return false;
        }
        return true;
    }

    void solve(int const &n, vector<vector<int>> &grid, int const &row, int &ans)
    {
        if (row == n)
        {
            ans++;
        }
        for (int j = 0; j < n; j++)
        {
            if (isSafe(n, grid, row, j))
            {
                grid[row][j] = 1;
                (solve(n, grid, row + 1, ans));
                grid[row][j] = 0;
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        int ans = 0;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        solve(n, grid, 0, ans);
        return ans;
    }
};