// https://leetcode.com/problems/combination-sum-iv/

/*Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

Example 2:

Input: nums = [9], target = 3
Output: 0

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

// Bottom up approach
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (auto &num : nums)
            {
                if (i - num >= 0)
                {
                    dp[i] += dp[i - num];
                }
                else
                {
                    break;
                }
            }
        }
        return dp[target];
    }
};

// Memoization - Top-down approach
class Solution
{
    int solve(vector<int> &nums, int target, vector<int> &dp)
    {
        if (target == 0)
        {
            return 1;
        }
        if (dp[target] != -1)
        {
            return dp[target];
        }
        dp[target] = 0;
        for (auto &num : nums)
        {
            if (target - num >= 0)
                dp[target] += solve(nums, target - num, dp);
        }
        return dp[target];
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};

// Brute Force
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        if (target == 0)
        {
            return 1;
        }
        int ans = 0;
        for (auto &num : nums)
        {
            if (target - num >= 0)
            {
                ans += combinationSum4(nums, target - num);
            }
        }
        return ans;
    }
};
