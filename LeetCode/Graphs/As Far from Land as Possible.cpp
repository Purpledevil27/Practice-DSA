// https://leetcode.com/problems/as-far-from-land-as-possible/

/*Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that
its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

Example 1:

Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

Example 2:

Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1

*/

#include <bits/stdc++.h>
using namespace std;

// Using BFS
class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q, q1;
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i - 1, j});
                    q.push({i, j - 1});
                    q.push({i + 1, j});
                    q.push({i, j + 1});
                }
            }
        }
        int step = 0;
        while (!q.empty())
        {
            step++;
            while (!q.empty())
            {
                pair<int, int> top = q.front();
                int i = top.first;
                int j = top.second;
                q.pop();

                if (i >= 0 && j >= 0 && j < n && i < n && grid[i][j] == 0)
                {
                    grid[i][j] = step;
                    q1.push({i - 1, j});
                    q1.push({i, j - 1});
                    q1.push({i + 1, j});
                    q1.push({i, j + 1});
                }
            }
            swap(q1, q);
        }
        if (step == 1)
        {
            return -1;
        }
        return step - 1;
    }
};

int main()
{
    int m;
    cin >> m;

    vector<vector<int>> grid(m, vector<int>(m));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.maxDistance(grid);

    return 0;
}