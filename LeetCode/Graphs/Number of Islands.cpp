// https://leetcode.com/problems/number-of-islands/

/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool help(vector<vector<char>> &grid, int r, int c, int i, int j, vector<vector<bool>> &visited)
    {
        if (i < 0 || j < 0 || i >= r || j >= c)
        {
            return true;
        }
        if (visited[i][j] || grid[i][j] == '0')
        {
            return true;
        }
        // cout << "en" << i << j << endl;
        visited[i][j] = true;
        if (help(grid, r, c, i + 1, j, visited) && help(grid, r, c, i, j + 1, visited) && help(grid, r, c, i - 1, j, visited) && help(grid, r, c, i, j - 1, visited))
        {
            return true;
        }
        return false;
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool check = false;
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    // cout << i << j <<endl;
                    // visited[i][j] = true;
                    check = help(grid, m, n, i, j, visited);
                }
                if (check)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.numIslands(grid);

    return 0;
}