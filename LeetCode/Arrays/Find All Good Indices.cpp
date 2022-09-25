// https://leetcode.com/problems/find-all-good-indices/

/*You are given a 0-indexed integer array nums of size n and a positive integer k.

We call an index i in the range k <= i < n - k good if the following conditions are satisfied:

The k elements that are just before the index i are in non-increasing order.
The k elements that are just after the index i are in non-decreasing order.
Return an array of all good indices sorted in increasing order.

Example 1:

Input: nums = [2,1,1,1,3,4,1], k = 2
Output: [2,3]
Explanation: There are two good indices in the array:
- Index 2. The subarray [2,1] is in non-increasing order, and the subarray [1,3] is in non-decreasing order.
- Index 3. The subarray [1,1] is in non-increasing order, and the subarray [3,4] is in non-decreasing order.
Note that the index 4 is not good because [4,1] is not non-decreasing.

Example 2:

Input: nums = [2,1,1,2], k = 2
Output: []
Explanation: There are no good indices in this array.

Constraints:
n == nums.length
3 <= n <= 10^5
1 <= nums[i] <= 10^6
1 <= k <= n / 2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> after(n), before(n);
        after[n - 1] = 1;
        vector<int> ans;
        if (k * 2 + 1 > nums.size())
        {
            return ans;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] <= nums[i + 1])
            {
                after[i] = after[i + 1] + 1;
            }
            else
            {
                after[i] = 1;
            }
        }

        before[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                before[i] = before[i - 1] + 1;
            }
            else
            {
                before[i] = 1;
            }
        }
        for (int i = k; i < n - k; i++)
        {
            if (before[i - 1] >= k && after[i + 1] >= k)
                ans.push_back(i);
        }
        return ans;
    }
};