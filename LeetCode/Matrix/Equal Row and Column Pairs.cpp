// https://leetcode.com/problems/equal-row-and-column-pairs/

/*Given a 0-indexed n x n integer matrix grid, return the number of pairs (Ri, Cj) such that row Ri and column Cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e. an equal array).

Example 1:

Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]

Example 2:

Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]

Constraints:
n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1 - O(N^2logN)
class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        map<vector<int>, int> rows;
        for (const auto &row : grid)
        {
            rows[row]++;
        }

        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> col;
            for (int j = 0; j < grid.size(); j++)
            {
                col.push_back(grid[j][i]);
            }
            ans += rows[col];
        }

        return ans;
    }
};

// Approach #2
class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> tranverse(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tranverse[i][j] = grid[j][i];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tranverse[j] == grid[i])
                    ans++;
            }
        }
        return ans;
    }
};