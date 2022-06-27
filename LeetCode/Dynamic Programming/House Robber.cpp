// https://leetcode.com/problems/house-robber/

/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only
constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will
automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob
tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};

// Memoization
class Solution
{
public:
    int solve(vector<int> &nums, int i, vector<int> &dp)
    {
        if (i < 0)
        {
            return 0;
        }
        if (dp[i] >= 0)
        {
            return dp[i];
        }
        return dp[i] = max(solve(nums, i - 1, dp), solve(nums, i - 2, dp) + nums[i]);
    }
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, -1);
        return solve(nums, nums.size() - 1, dp);
    }
};

// Brute Force Approach
class Solution
{
public:
    int solve(vector<int> &nums, int i, int sum)
    {
        if (i < 0)
        {
            return sum;
        }
        return max(solve(nums, i - 1, sum), solve(nums, i - 2, sum + nums[i]));
    }
    int rob(vector<int> &nums)
    {
        return solve(nums, nums.size() - 1, 0);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        v.push_back(k);
    }

    Solution obj;
    cout << obj.rob(v);

    return 0;
}