// https://leetcode.com/problems/01-matrix/

/*Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Example 1:

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 10^4
1 <= m * n <= 10^4
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        int dist[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        q.push({-1, -1});
        int step = 1;
        while (!q.empty())
        {
            pair<int, int> f = q.front();
            q.pop();
            if (f.first == -1)
            {

                if (q.empty())
                    break;
                q.push({-1, -1});
                step++;
                continue;
            }
            cout << step << endl;
            for (int i = 0; i < 4; i++)
            {
                int r = f.first + dist[i][0];
                int c = f.second + dist[i][1];
                if (r >= m || c >= n || r < 0 || c < 0 || vis[r][c] == 1)
                {
                    continue;
                }
                grid[r][c] = step;
                vis[r][c] = 1;
                q.push({r, c});
            }
        }
        return grid;
    }
};

// Approach #2
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int row = mat.size();
        int col = mat[0].size();
        int maxVal = row + col;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (mat[i][j] == 0)
                    continue;
                int top = maxVal;
                int left = maxVal;
                if (i >= 1)
                    top = mat[i - 1][j];
                if (j >= 1)
                    left = mat[i][j - 1];
                mat[i][j] = min(top, left) + 1;
            }
        }
        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = col - 1; j >= 0; j--)
            {
                if (mat[i][j] == 0)
                    continue;
                int bottom = maxVal;
                int right = maxVal;
                if (i < row - 1)
                    bottom = mat[i + 1][j];
                if (j < col - 1)
                    right = mat[i][j + 1];
                mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};