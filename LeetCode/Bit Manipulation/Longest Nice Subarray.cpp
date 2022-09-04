// https://leetcode.com/problems/longest-nice-subarray/

/*You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.
Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.
Note that subarrays of length 1 are always considered nice.

Example 1:

Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.

Example 2:

Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    int longestNiceSubarray(vector<int> &res)
    {
        int used = 0, j = 0, ans = 0;
        for (int i = 0; i < res.size(); ++i)
        {
            // if bitwise AND is not zero, then remove that number
            while ((used & res[i]) != 0)
                used ^= res[j++];
            // add the number
            used |= res[i];
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};

// Approach #2
class Solution
{
public:
    int longestNiceSubarray(vector<int> &res)
    {
        int size = res.size(), end = 1, start = 0, ans = 1;
        while (end < size)
        {
            bool isNice = true;
            // for a 32-bit interger
            int rem_bit = 32;
            for (int i = end - 1; i >= start && rem_bit; i--)
            {
                if (res[end] & res[i])
                {
                    isNice = false;
                    break;
                }
                rem_bit--;
            }
            if (isNice == true)
            {
                ans = max(ans, end - start + 1);
                end += 1;
            }
            else
            {
                start += 1;
            }
        }
        return ans;
    }
};