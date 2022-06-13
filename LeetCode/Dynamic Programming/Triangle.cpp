// https://leetcode.com/problems/triangle/

/*Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you
may move to either index i or index i + 1 on the next row.

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:

Input: triangle = [[-10]]
Output: -10

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-10^4 <= triangle[i][j] <= 10^4

*/

#include <bits/stdc++.h>
using namespace std;

// Using O(n) space complexity
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> store = triangle[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                store[j] = triangle[i][j] + min(store[j], store[j + 1]);
            }
        }
        return store[0];
    }
};

// Using O(n^2) space complexity
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0] = triangle[0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < triangle[i - 1].size(); j++)
            {
                dp[i][j] = min(dp[i][j], triangle[i][j] + dp[i - 1][j]);
                dp[i][j + 1] = min(dp[i][j + 1], triangle[i][j + 1] + dp[i - 1][j]);
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
