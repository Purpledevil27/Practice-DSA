// https://leetcode.com/problems/number-of-closed-islands/

/*Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Example 1:

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation:
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:

Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

Constraints:
1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &board, int i, int j, int const &m, int const &n)
    {
        if (i >= m || j >= n || i < 0 || j < 0 || board[i][j] == 1)
        {
            return;
        }
        board[i][j] = 1;
        dfs(board, i, j + 1, m, n);
        dfs(board, i + 1, j, m, n);
        dfs(board, i - 1, j, m, n);
        dfs(board, i, j - 1, m, n);
    }

public:
    int closedIsland(vector<vector<int>> &board)
    {
        int m = board.size(), n = board[0].size(), ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == m - 1 || j == n - 1 || j == 0 && board[i][j] == 0)
                {
                    dfs(board, i, j, m, n);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 0)
                {
                    dfs(board, i, j, m, n);
                    ans++;
                }
            }
        }
        return ans;
    }
};