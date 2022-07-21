// https://leetcode.com/problems/longest-increasing-subsequence/

/*Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

Constraints:
1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

// Using Bottom Up Dynamic Programming
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(), ans = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(dp[i], ans);
                }
            }
        }
        return ans;
    }
};

// Using Binary search
class Solution
{
public:
    int lengthOfLIS(vector<int> &A)
    {
        int len = 0;
        for (auto cur : A)
            if (len == 0 || A[len - 1] < cur)
                A[len++] = cur; // extend
            else
                *lower_bound(begin(A), begin(A) + len, cur) = cur; // replace
        return len;
    }
};