// https://leetcode.com/problems/pascals-triangle/

/*Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:
1 <= numRows <= 30
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> dp(n);
        int i = 0;
        for (; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    dp[i].push_back(1);
                }
                else
                {
                    dp[i].push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
                }
            }
        }
        return dp;
    }
};