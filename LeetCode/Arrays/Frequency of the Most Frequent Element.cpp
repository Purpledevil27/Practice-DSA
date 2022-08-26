// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

/*The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.

Example 2:

Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.

Example 3:

Input: nums = [3,9,6], k = 2
Output: 1

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
1 <= k <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Brute force
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int ans = INT_MIN, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int t = k, tans = 1;
            // Pruning for duplicate elements
            if (i != 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n && t > 0; j++)
            {
                int diff = nums[i] - nums[j];
                if (t - diff >= 0)
                {
                    tans++;
                }
                t -= diff;
            }
            ans = max(tans, ans);
        }
        return ans;
    }
};

// Sliding Window
class Solution
{
public:
    int maxFrequency(vector<int> &nums, long k)
    {
        int i = 0, j;
        sort(nums.begin(), nums.end());
        for (j = 0; j < nums.size(); j++)
        {
            k = k + nums[j];
            if (k < (long)(j - i + 1) * nums[j])
            {
                k = k - nums[i];
                i++;
            }
        }
        return j - i;
    }
};