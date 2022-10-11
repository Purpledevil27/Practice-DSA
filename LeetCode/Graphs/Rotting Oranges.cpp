// https://leetcode.com/problems/rotting-oranges/

/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int dist[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        int m = grid.size(), n = grid[0].size(), ans = 0, count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                if (grid[i][j] == 1)
                {
                    count++;
                }
            }
        }
        if (count == 0)
            return 0;
        q.push({-1, -1});
        while (!q.empty())
        {
            pair<int, int> f = q.front();
            q.pop();
            if (f.first == -1)
            {
                if (q.empty())
                    break;
                ans++;
                if (!q.empty())
                {
                    q.push({-1, -1});
                }
                continue;
            }
            for (int i = 0; i < 4; i++)
            {
                int r = f.first + dist[i][0];
                int c = f.second + dist[i][1];
                if (r >= m || c >= n || r < 0 || c < 0 || grid[r][c] != 1)
                {
                    continue;
                }
                grid[r][c] = 2;
                count--;
                q.push({r, c});
            }
        }
        return count == 0 ? ans : -1;
    }
};