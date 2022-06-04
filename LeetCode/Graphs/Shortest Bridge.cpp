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
    void findFirstIsland(vector<vector<int>> &grid, int i, int j, int n, vector<vector<bool>> &partOfIsland, queue<int> &qi, queue<int> &qj)
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
        findFirstIsland(grid, i + 1, j, n, partOfIsland, qi, qj);
        findFirstIsland(grid, i, j + 1, n, partOfIsland, qi, qj);
        findFirstIsland(grid, i - 1, j, n, partOfIsland, qi, qj);
        findFirstIsland(grid, i, j - 1, n, partOfIsland, qi, qj);
    }

    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size(), ans = 0;

        queue<int> qi, qj;

        int i, j, oi, oj;
        bool first = false;

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
                    step[x][y] = 0;
                    first = true;
                    goto label;
                    // break;
                }
            }
            // if (first)
            //     break;
        }
    label:

        findFirstIsland(grid, oi, oj, n, partOfIsland, qi, qj);

        while (!qi.empty() && !qj.empty())
        {

            i = qi.front();
            j = qj.front();
            // cout << i + 1 << " " << j + 1 << endl;
            qi.pop();
            qj.pop();

            // for grid[i][j]==1
            if (i + 1 < n && grid[i][j] == 1)
            {
                if (grid[i + 1][j] == 1 && step[i + 1][j] != 0)
                {
                    step[i + 1][j] = 0;
                }
                else if (grid[i + 1][j] == 0)
                {
                    if (step[i + 1][j] != -1)
                    {
                        step[i + 1][j] = min(step[i][j] + 1, step[i + 1][j]);
                    }
                    else
                    {
                        qi.push(i + 1);
                        qj.push(j);
                        step[i + 1][j] = 0;
                    }
                }
            }
            if (j + 1 < n && grid[i][j] == 1)
            {
                if (grid[i][j + 1] == 1 && step[i][j + 1] != 0)
                {
                    step[i][j + 1] = 0;
                }
                else if (grid[i][j + 1] == 0)
                {
                    if (step[i][j + 1] != -1)
                    {
                        step[i][j + 1] = min(step[i][j] + 1, step[i][j + 1]);
                    }
                    else
                    {
                        qi.push(i);
                        qj.push(j + 1);
                        step[i][j + 1] = 0;
                    }
                }
            }
            if (i - 1 >= 0 && grid[i][j] == 1)
            {
                if (grid[i - 1][j] == 1 && step[i - 1][j] != 0)
                {
                    step[i - 1][j] = 0;
                }
                else if (grid[i - 1][j] == 0)
                {
                    if (step[i - 1][j] != -1)
                    {
                        step[i - 1][j] = min(step[i][j] + 1, step[i - 1][j]);
                    }
                    else
                    {
                        qi.push(i - 1);
                        qj.push(j);
                        step[i - 1][j] = 0;
                    }
                }
            }
            if (j - 1 >= 0 && grid[i][j] == 1)
            {
                if (grid[i][j - 1] == 1 && step[i][j - 1] != 0)
                {
                    step[i][j - 1] = 0;
                }
                else if (grid[i][j - 1] == 0)
                {
                    if (step[i][j - 1] != -1)
                    {
                        step[i][j - 1] = min(step[i][j] + 1, step[i][j - 1]);
                    }
                    else
                    {
                        qi.push(i);
                        qj.push(j - 1);
                        step[i][j - 1] = 0;
                    }
                }
            }

            // for grid[i][j]==0
            if (i + 1 < n && grid[i][j] == 0)
            {
                if (grid[i + 1][j] == 0)
                {
                    if (step[i + 1][j] != -1)
                    {
                        step[i + 1][j] = min(step[i][j] + 1, step[i + 1][j]);
                    }
                    else
                    {
                        qi.push(i + 1);
                        qj.push(j);
                        step[i + 1][j] = step[i][j] + 1;
                    }
                }
                else if (grid[i + 1][j] == 1 && !partOfIsland[i + 1][j])
                {
                    ans = step[i][j] + 1;
                    break;
                }
            }
            if (j + 1 < n && grid[i][j] == 0)
            {
                if (grid[i][j + 1] == 0)
                {
                    if (step[i][j + 1] != -1)
                    {
                        step[i][j + 1] = min(step[i][j] + 1, step[i][j + 1]);
                    }
                    else
                    {
                        qi.push(i);
                        qj.push(j + 1);
                        step[i][j + 1] = step[i][j] + 1;
                    }
                }
                else if (grid[i][j + 1] == 1 && !partOfIsland[i][j + 1])
                {
                    ans = step[i][j] + 1;
                    break;
                }
            }
            if (i - 1 >= 0 && grid[i][j] == 0)
            {
                if (grid[i - 1][j] == 0)
                {
                    if (step[i - 1][j] != -1)
                    {
                        step[i - 1][j] = min(step[i][j] + 1, step[i - 1][j]);
                    }
                    else
                    {
                        qi.push(i - 1);
                        qj.push(j);
                        step[i - 1][j] = step[i][j] + 1;
                    }
                }
                else if (grid[i - 1][j] == 1 && !partOfIsland[i - 1][j])
                {
                    ans = step[i][j] + 1;
                    break;
                }
            }
            if (j - 1 >= 0 && grid[i][j] == 0)
            {
                if (grid[i][j - 1] == 0)
                {
                    if (step[i][j - 1] != -1)
                    {
                        step[i][j - 1] = min(step[i][j] + 1, step[i][j - 1]);
                    }
                    else
                    {
                        qi.push(i);
                        qj.push(j - 1);
                        step[i][j - 1] = step[i][j] + 1;
                    }
                }
                else if (grid[i][j - 1] == 1 && !partOfIsland[i][j - 1])
                {
                    ans = step[i][j] + 1;
                    break;
                }
            }
        }
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
5 5
1 1 1 1 1
1 0 0 0 1
1 0 1 0 1
1 0 0 0 1
1 1 1 1 1
*/