// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

/*You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
Return true if the array has at least one valid partition. Otherwise, return false.

Example 1:

Input: nums = [4,4,4,5,6]
Output: true
Explanation: The array can be partitioned into the subarrays [4,4] and [4,5,6].
This partition is valid, so we return true.

Example 2:

Input: nums = [1,1,1,2]
Output: false
Explanation: There is no valid partition for this array.

Constraints:
2 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 2)
            return nums[0] == nums[1];

        vector<bool> dp(n + 1, false);
        dp[0] = true;
        dp[1] = false;
        if (nums[0] == nums[1])
            dp[2] = true;
        for (int i = 3; i <= n; i++)
        {
            bool ans = false;
            if (nums[i - 1] == nums[i - 2])
                ans = (ans || dp[i - 2]);
            if (nums[i - 1] == nums[i - 2] && nums[i - 3] == nums[i - 2])
                ans = ans || dp[i - 3];
            if (nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1)
                ans = ans || dp[i - 3];
            dp[i] = ans;
        }
        return dp[n];
    }
};