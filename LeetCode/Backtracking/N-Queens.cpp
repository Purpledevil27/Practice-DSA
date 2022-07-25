// https://leetcode.com/problems/n-queens/

/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:

Input: n = 1
Output: [["Q"]]

Constraints:
1 <= n <= 9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<string>> ans;

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

    void solve(int n, vector<vector<int>> &grid, int row)
    {
        if (row == n)
        {
            vector<string> v;
            for (int i = 0; i < n; i++)
            {
                string s = "";
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 0)
                        s += '.';
                    else
                        s += 'Q';
                }
                v.push_back(s);
            }
            ans.push_back(v);
        }
        for (int j = 0; j < n; j++)
        {
            if (isSafe(n, grid, row, j))
            {
                grid[row][j] = 1;
                (solve(n, grid, row + 1));
                grid[row][j] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        solve(n, grid, 0);
        return ans;
    }
};