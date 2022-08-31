// https://leetcode.com/problems/pacific-atlantic-water-flow/

/*There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height.
Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example 1:

Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

Constraints:
m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int i, int j, int &m, int &n, vector<vector<int>> &heights, vector<vector<int>> &po, int prev)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || heights[i][j] < prev || po[i][j] == 1)
        {
            return;
        }
        po[i][j] = 1;

        dfs(i + 1, j, m, n, heights, po, heights[i][j]);
        dfs(i, j + 1, m, n, heights, po, heights[i][j]);
        dfs(i, j - 1, m, n, heights, po, heights[i][j]);
        dfs(i - 1, j, m, n, heights, po, heights[i][j]);
    }

    void dfs2(int i, int j, int &m, int &n, vector<vector<int>> &heights, vector<vector<int>> &po, int prev, vector<vector<int>> &ao, vector<vector<int>> &ans)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || heights[i][j] < prev || ao[i][j] == 1)
        {
            return;
        }

        ao[i][j] = 1;
        if (po[i][j] == 1)
        {
            ans.push_back({i, j});
        }
        dfs2(i + 1, j, m, n, heights, po, heights[i][j], ao, ans);
        dfs2(i, j + 1, m, n, heights, po, heights[i][j], ao, ans);
        dfs2(i, j - 1, m, n, heights, po, heights[i][j], ao, ans);
        dfs2(i - 1, j, m, n, heights, po, heights[i][j], ao, ans);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> po(m, vector<int>(n, 0)), ao(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dfs(i, j, m, n, heights, po, heights[i][j]);
                }
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == m - 1 || j == n - 1)
                {
                    dfs2(i, j, m, n, heights, po, heights[i][j], ao, ans);
                }
            }
        }

        return ans;
    }
};