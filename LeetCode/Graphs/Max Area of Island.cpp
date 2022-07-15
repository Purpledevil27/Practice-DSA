// https://leetcode.com/problems/max-area-of-island/

/*You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &grid, int i, int j, const int &m, const int &n, int &smallans)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1)
            return;
        smallans += 1;  // incrementing answer
        grid[i][j] = 0; // marking as visited

        // Recursion calls
        dfs(grid, i - 1, j, m, n, smallans);
        dfs(grid, i, j + 1, m, n, smallans);
        dfs(grid, i, j - 1, m, n, smallans);
        dfs(grid, i + 1, j, m, n, smallans);
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int smallans = 0;
                    dfs(grid, i, j, m, n, smallans);
                    ans = max(smallans, ans);
                }
            }
        }
        return ans;
    }
};