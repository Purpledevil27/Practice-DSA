// https://leetcode.com/problems/out-of-boundary-paths/

/*There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball
to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 10^9 + 7.

Example 1:

Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Example 2:

Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12

Constraints:
1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n
*/

#include <bits/stdc++.h>
using namespace std;

// Using Dp- Tabulation Bottom up
#define MOD 1000000007
class Solution
{
public:
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn)
    {
        if (maxMove == 0)
            return 0;
        long long dp[maxMove][n][m];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            dp[0][i][0] += 1;
            dp[0][i][m - 1] += 1;
        }
        for (int j = 0; j < m; j++)
        {
            dp[0][0][j] += 1;
            dp[0][n - 1][j] += 1;
        }
        for (int k = 1; k < maxMove; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    dp[k][i][j] = ((i + 1 < n ? dp[k - 1][i + 1][j] : 0) +
                                   (j - 1 >= 0 ? dp[k - 1][i][j - 1] : 0) +
                                   (j + 1 < m ? dp[k - 1][i][j + 1] : 0) +
                                   (i - 1 >= 0 ? dp[k - 1][i - 1][j] : 0)) %
                                  MOD;
                }
            }
        }
        long long sum = 0;
        for (int k = 0; k < maxMove; k++)
        {
            sum += dp[k][startRow][startColumn];
            sum %= MOD;
        }
        return sum;
    }
};

// Using Memoization - Top Down
#define MOD 1000000007
class Solution
{
    long long dp[51][51][51];
    long long helper(const int &row, const int &col, int m, int i, int j)
    {
        if (i < 0 || j < 0 || i >= row || j >= col || m < 0)
        {
            if (m >= 0)
            {
                return 1;
            }
            return 0;
        }
        if (dp[m][i][j] != -1)
        {
            return dp[m][i][j];
        }
        return dp[m][i][j] = ((helper(row, col, m - 1, i + 1, j) + helper(row, col, m - 1, i - 1, j) + helper(row, col, m - 1, i, j + 1) + helper(row, col, m - 1, i, j - 1)) % MOD);
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return helper(m, n, maxMove, startRow, startColumn);
    }
};