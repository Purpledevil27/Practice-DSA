// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return {-1, -1};
        int first_occur = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        first_occur = (first_occur < nums.size() && nums[first_occur] == target) ? first_occur : -1;
        int last_occur = upper_bound(nums.begin(), nums.end(), target) - 1 - nums.begin();
        last_occur = (last_occur >= 0 && nums[last_occur] == target) ? last_occur : -1;
        return {first_occur, last_occur};
    }
};

class Solution
{
    int binarySearchFirst(vector<int> &nums, int const &target)
    {
        int start = 0, end = nums.size() - 1, ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }

    int binarySearchLast(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1, ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                ans = mid;
                start = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int const &target)
    {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};
        int first = binarySearchFirst(nums, target);
        int last = binarySearchLast(nums, target);
        return {first, last};
    }
};