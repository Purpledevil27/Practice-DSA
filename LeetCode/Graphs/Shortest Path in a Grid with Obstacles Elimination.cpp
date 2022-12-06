// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

/*You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

Example 1:

Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation:
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).

Example 2:

Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 40
1 <= k <= m * n
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, -1));
        int dis[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        if (grid[0][0] == 1)
        {
            k--;
        }
        q.push({{0, 0}, k});
        int ans = -1;
        while (!q.empty())
        {
            int size = q.size();
            ans++;
            for (int i = 0; i < size; i++)
            {
                auto it = q.front();
                q.pop();
                int x = it.first.first, y = it.first.second, rem = it.second;
                if (x == m - 1 && y == n - 1)
                {
                    return ans;
                }

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dis[i][0], ny = y + dis[i][1];
                    if (nx < 0 || ny < 0 || nx >= m | ny >= n || (grid[nx][ny] == 1 && rem == 0))
                    {
                        continue;
                    }

                    if (visited[nx][ny] != -1 && visited[nx][ny] >= rem)
                    {
                        continue;
                    }

                    if (grid[nx][ny] == 1)
                    {
                        q.push({{nx, ny}, rem - 1});
                        visited[nx][ny] = rem - 1;
                    }
                    else if (grid[nx][ny] == 0)
                    {
                        q.push({{nx, ny}, rem});
                        visited[nx][ny] = rem;
                    }
                }
            }
        }
        return -1;
    }
};