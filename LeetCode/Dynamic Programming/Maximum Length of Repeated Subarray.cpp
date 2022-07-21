// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

/*Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

// Bottom Top 1D Dp
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1 == nums2)
            return nums2.size();
        int n = nums1.size(), m = nums2.size(), ans = 0;
        vector<int> dp(m + 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j > 0; j--)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[j] = dp[j - 1] + 1;
                    ans = max(ans, dp[j]);
                }
                else
                {
                    dp[j] = 0;
                }
            }
        }
        return ans;
    }
};

// Bottom Top 2D Dp
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1 == nums2)
            return nums2.size();
        int n = nums1.size(), m = nums2.size(), ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

// Top-bottom Memoization
class Solution
{
    vector<vector<int>> dp;
    int ans = 0;
    int solve(vector<int> &A, vector<int> &B, int i, int j)
    {
        if (i >= A.size() || j >= B.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        solve(A, B, i + 1, j), solve(A, B, i, j + 1);
        dp[i][j] = A[i] == B[j] ? solve(A, B, i + 1, j + 1) + 1 : 0; // store the result for state (i, j) for future
        ans = max(ans, dp[i][j]);
        return dp[i][j];
    }

public:
    int findLength(vector<int> &A, vector<int> &B)
    {
        dp.resize(A.size(), vector<int>(B.size(), -1));
        solve(A, B, 0, 0);
        return ans;
    }
};