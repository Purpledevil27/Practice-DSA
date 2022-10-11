// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/

/*You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.

Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 10^9 + 7.

Example 1:

Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
Output: 2
Explanation: There are two paths where the sum of the elements on the path is divisible by k.
The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.

Example 2:

Input: grid = [[0,0]], k = 5
Output: 1
Explanation: The path highlighted in red has a sum of 0 + 0 = 0 which is divisible by 5.

Example 3:

Input: grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
Output: 10
Explanation: Every integer is divisible by 1 so the sum of the elements on every possible path is divisible by k.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 5 * 10^4
1 <= m * n <= 5 * 10^4
0 <= grid[i][j] <= 100
1 <= k <= 50
*/

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
class Solution
{
    int m, n, k;
    int solve(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int i, int j, int sum)
    {
        if (i == m || j == n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return (((sum + grid[i][j]) % k) == 0) ? 1 : 0;
        if (dp[i][j][sum] != -1)
            return dp[i][j][sum];
        return dp[i][j][sum] = (solve(grid, dp, i + 1, j, (sum + grid[i][j]) % k) +
                                solve(grid, dp, i, j + 1, (sum + grid[i][j]) % k)) %
                               mod;
    }

public:
    int numberOfPaths(vector<vector<int>> &grid, int kk)
    {
        m = grid.size(), n = grid[0].size(), k = kk;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        return solve(grid, dp, 0, 0, 0);
    }
};