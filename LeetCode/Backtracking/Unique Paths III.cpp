// https://leetcode.com/problems/unique-paths-iii/

/*You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Example 1:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:

Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 20
1 <= m * n <= 20
-1 <= grid[i][j] <= 2
There is exactly one starting cell and one ending cell.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<vector<int>> &grid, int const &m, int const &n, int &ans, int step, int i, int j)
    {
        if (i >= m || j >= n || j < 0 || i < 0 || grid[i][j] == -1 || (step != 0 && grid[i][j] == 2))
            return;
        if (step == 0)
        {
            if (grid[i][j] == 2)
                ans++;
            return;
        }
        grid[i][j] = -1;
        solve(grid, m, n, ans, step - 1, i + 1, j);
        solve(grid, m, n, ans, step - 1, i, j + 1);
        solve(grid, m, n, ans, step - 1, i - 1, j);
        solve(grid, m, n, ans, step - 1, i, j - 1);
        grid[i][j] = 0;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), step = 0, row = 0, col = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    row = i;
                    col = j;
                }
                if (grid[i][j] == 0)
                    step++;
            }
        }
        int ans = 0;
        solve(grid, m, n, ans, step + 1, row, col);
        return ans;
    }
};