// https://leetcode.com/problems/ones-and-zeroes/

/*You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.



Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.


Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100
*/

#include <bits/stdc++.h>
using namespace std;

// Using Dp
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (auto s : strs)
        {
            int x = count(s.begin(), s.end(), '1');
            int y = s.size() - x;

            for (int i = m; i >= y; i--)
            {
                for (int j = n; j >= x; j--)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - y][j - x]);
                }
            }
        }
        return dp[m][n];
    }
};

// Memoization
class Solution
{
public:
    int dp[601][101][101];
    int solve(vector<pair<int, int>> &num, int index, int rem0, int rem1)
    {
        if (index == num.size() || (rem0 == 0 && rem1 == 0))
        {
            return 0;
        }
        if (dp[index][rem0][rem1] != -1)
        {
            return dp[index][rem0][rem1];
        }
        if (num[index].first > rem0 || num[index].second > rem1)
        {
            return dp[index][rem0][rem1] = solve(num, index + 1, rem0, rem1);
        }

        return dp[index][rem0][rem1] = max(solve(num, index + 1, rem0, rem1), 1 + solve(num, index + 1, rem0 - num[index].first, rem1 - num[index].second));
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        vector<pair<int, int>> num;
        for (auto i : strs)
        {
            int one = 0, zero = 0;
            for (auto j : i)
            {
                (j == '1') ? one++ : zero++;
            }
            num.push_back({zero, one});
        }

        return solve(num, 0, m, n);
    }
};

// Recursion
class Solution
{
public:
    int solve(vector<pair<int, int>> &num, int index, int rem0, int rem1)
    {
        if (index == num.size() || (rem0 == 0 && rem1 == 0))
        {
            return 0;
        }
        if (num[index].first > rem0 || num[index].second > rem1)
        {
            return solve(num, index + 1, rem0, rem1);
        }

        return max(solve(num, index + 1, rem0, rem1), 1 + solve(num, index + 1, rem0 - num[index].first, rem1 - num[index].second));
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<pair<int, int>> num;
        for (auto i : strs)
        {
            int one = 0, zero = 0;
            for (auto j : i)
            {
                (j == '1') ? one++ : zero++;
            }
            num.push_back({zero, one});
        }

        return solve(num, 0, m, n);
    }
};
