// https://leetcode.com/problems/contains-duplicate-ii/

/*Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

Constraints:
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
0 <= k <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int start = 0, end = 0;
        unordered_map<int, int> m;

        while (end < nums.size())
        {
            if (m[nums[end]] != 0)
            {
                return true;
            }
            if (end - start >= k)
            {
                m[nums[start++]]--;
            }
            m[nums[end++]]++;
        }
        return false;
    }
};