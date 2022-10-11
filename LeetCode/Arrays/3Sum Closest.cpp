// https://leetcode.com/problems/3sum-closest/

/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

Constraints:
3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-10^4 <= target <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        int i = 0, i1 = 0, j = n - 1;
        int diff = INT_MAX, ans = -1;
        sort(nums.begin(), nums.end());
        while (i < n - 2)
        {
            i1 = i + 1, j = n - 1;
            while (i1 < j)
            {
                int sum = nums[i] + nums[i1] + nums[j];
                if (sum - target < 0)
                {
                    i1++;
                    while (i1 < j && nums[i1] == nums[i1 - 1])
                    {
                        i1++;
                    }
                }
                else if (sum - target > 0)
                {
                    j--;
                    while (i1 < j && nums[j] == nums[j + 1])
                    {
                        j--;
                    }
                }
                else
                {
                    return target;
                }
                if (diff > abs(target - (sum)))
                {
                    diff = abs(target - (sum));
                    ans = sum;
                }
            }
            i++;
            while (i < n - 2 && nums[i] == nums[i - 1])
            {
                i++;
            }
        }
        return ans;
    }
};