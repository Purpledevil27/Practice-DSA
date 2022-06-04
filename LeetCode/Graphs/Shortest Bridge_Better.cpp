// https://leetcode.com/problems/shortest-bridge/

/*You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1

Constraints:

n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void findFirstIsland(vector<vector<int>> &grid, int i, int j, int n, vector<vector<bool>> &partOfIsland, queue<int> &qi, queue<int> &qj, vector<vector<int>> &step)
    {

        if (i < 0 || j < 0 || i >= n || j >= n)
        {
            return;
        }
        if (partOfIsland[i][j] || grid[i][j] == 0)
        {
            return;
        }
        qi.push(i);
        qj.push(j);

        partOfIsland[i][j] = true;
        step[i][j] = 0;

        findFirstIsland(grid, i + 1, j, n, partOfIsland, qi, qj, step);
        findFirstIsland(grid, i, j + 1, n, partOfIsland, qi, qj, step);
        findFirstIsland(grid, i - 1, j, n, partOfIsland, qi, qj, step);
        findFirstIsland(grid, i, j - 1, n, partOfIsland, qi, qj, step);
    }

    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size(), ans = 0;

        queue<int> qi, qj;

        int i, j, oi, oj;

        vector<vector<bool>> partOfIsland(n, vector<bool>(n, false));
        vector<vector<int>> step(n, vector<int>(n, -1));
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (grid[x][y] == 1)
                {
                    oi = x;
                    oj = y;
                    goto label;
                }
            }
        }
    label:

        findFirstIsland(grid, oi, oj, n, partOfIsland, qi, qj, step);

        while (!qi.empty() && !qj.empty())
        {

            i = qi.front();
            j = qj.front();
            qi.pop();
            qj.pop();

            for (int k = 0; k < 4; k++)
            {
                int x = i + direction[k][0];
                int y = j + direction[k][1];

                if (x < 0 || y < 0 || x >= n || y >= n)
                    continue;

                if (grid[x][y] == 0)
                {
                    if (step[x][y] != -1)
                    {
                        step[x][y] = min(step[i][j] + 1, step[x][y]);
                    }
                    else
                    {
                        qi.push(x);
                        qj.push(y);
                        if (grid[i][j] == 1)
                        {
                            step[x][y] = 0;
                        }
                        else if (grid[i][j] == 0)
                        {
                            step[x][y] = step[i][j] + 1;
                        }
                    }
                }
                else if (grid[x][y] == 1 && !partOfIsland[x][y])
                {
                    ans = step[i][j] + 1;
                    goto finale;
                }
            }
        }
    finale:
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.shortestBridge(grid);

    return 0;
}

/*
5
1 1 1 1 1
1 0 0 0 1
1 0 1 0 1
1 0 0 0 1
1 1 1 1 1
*/