// https://leetcode.com/problems/knight-dialer/

/*The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one
square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:

We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).

Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 10^9 + 7.

Example 1:

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.

Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]

Example 3:

Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.

Constraints:
1 <= n <= 5000
*/

#include <bits/stdc++.h>
using namespace std;

// Using Dp - Approach #1
class Solution
{
public:
    int knightDialer(int n)
    {
        if (n == 1)
            return 10;
        vector<int> dp1(10, 1), dp2(10, 0);
        int mod = 1000000007;
        for (int i = 1; i < n; i++)
        {
            dp2[0] = (dp1[4] + dp1[6]) % mod;
            dp2[1] = (dp1[6] + dp1[8]) % mod;
            dp2[2] = (dp1[7] + dp1[9]) % mod;
            dp2[3] = (dp1[4] + dp1[8]) % mod;
            dp2[4] = ((dp1[0] + dp1[3]) % mod + dp1[9]) % mod;
            dp2[6] = ((dp1[0] + dp1[1]) % mod + dp1[7]) % mod;
            dp2[7] = (dp1[2] + dp1[6]) % mod;
            dp2[8] = (dp1[1] + dp1[3]) % mod;
            dp2[9] = (dp1[2] + dp1[4]) % mod;
            dp1 = dp2;
        }
        return accumulate(dp1.begin(), dp1.end(), 0, [](int s, int n)
                          { return (s + n) % 1000000007; });
    }
};

// Better Code For approach #1
class Solution
{
public:
    vector<vector<int>> ms = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
    int knightDialer(int N)
    {
        vector<int> d1(10, 1), d2(10);
        for (; --N > 0; swap(d1, d2))
            for (auto i = 0; i < 10; ++i)
                d2[i] = accumulate(begin(ms[i]), end(ms[i]), 0, [&](int s, int i)
                                   { return (s + d1[i]) % 1000000007; });
        return accumulate(begin(d1), end(d1), 0, [](int s, int n)
                          { return (s + n) % 1000000007; });
    }
};

// Using Memoization - Approach #2
class Solution
{
public:
    int dp[5001][4][3];
    int mod = 1000000007;
    int direction[8][2] = {{-1, -2}, {-2, -1}, {-2, +1}, {-1, +2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
    int solve(vector<vector<char>> &numpad, int n, int row, int col)
    {
        int ans = 0;
        if (n == 0)
        {
            return 1;
        }
        if (dp[n][row][col] != -1)
        {
            return dp[n][row][col];
        }
        for (int i = 0; i < 8; i++)
        {
            int x = row + direction[i][0];
            int y = col + direction[i][1];

            if (x < 0 || y < 0 || x >= 4 || y >= 3)
                continue;
            if (numpad[x][y] != '*' && numpad[x][y] != '#')
            {
                ans = (ans + solve(numpad, n - 1, x, y)) % mod;
            }
        }
        return dp[n][row][col] = ans;
    }
    int knightDialer(int n)
    {
        vector<vector<char>> numpad(4, vector<char>(3));

        memset(dp, -1, sizeof(dp));
        numpad = {{'1', '2', '3'},
                  {'4', '5', '6'},
                  {'7', '8', '9'},
                  {'*', '0', '#'}};
        int ans = 0;
        for (int i = 0; i < numpad.size(); i++)
        {
            for (int j = 0; j < numpad[i].size(); j++)
            {
                if (numpad[i][j] != '*' && numpad[i][j] != '#')
                {
                    ans = (ans + solve(numpad, n - 1, i, j)) % mod;
                }
            }
        }
        return ans;
    }
};

// Using Recusion - Approach #3
class Solution
{
public:
    int dp[5001][4][3];
    int mod = 1000000007;
    int direction[8][2] = {{-1, -2}, {-2, -1}, {-2, +1}, {-1, +2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
    int solve(vector<vector<char>> &numpad, int n, int row, int col)
    {
        int ans = 0;
        if (n == 0)
        {
            return 1;
        }
        if (dp[n][row][col] != -1)
        {
            return dp[n][row][col];
        }
        for (int i = 0; i < 8; i++)
        {
            int x = row + direction[i][0];
            int y = col + direction[i][1];

            if (x < 0 || y < 0 || x >= 4 || y >= 3)
                continue;
            if (numpad[x][y] != '*' && numpad[x][y] != '#')
            {
                ans = (ans + solve(numpad, n - 1, x, y)) % mod;
            }
        }
        return dp[n][row][col] = ans;
    }
    int knightDialer(int n)
    {
        vector<vector<char>> numpad(4, vector<char>(3));

        memset(dp, -1, sizeof(dp));
        numpad = {{'1', '2', '3'},
                  {'4', '5', '6'},
                  {'7', '8', '9'},
                  {'*', '0', '#'}};
        int ans = 0;
        for (int i = 0; i < numpad.size(); i++)
        {
            for (int j = 0; j < numpad[i].size(); j++)
            {
                if (numpad[i][j] != '*' && numpad[i][j] != '#')
                {
                    ans = (ans + solve(numpad, n - 1, i, j)) % mod;
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
    Solution obj;
    cout << obj.knightDialer(n);
    return 0;
}
