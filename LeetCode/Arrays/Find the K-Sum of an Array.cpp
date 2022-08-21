// https://leetcode.com/problems/find-the-k-sum-of-an-array/

/*You are given an integer array nums and a positive integer k. You can choose any subsequence of the array and sum all of its elements together.

We define the K-Sum of the array as the kth largest subsequence sum that can be obtained (not necessarily distinct).

Return the K-Sum of the array.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Note that the empty subsequence is considered to have a sum of 0.

Example 1:

Input: nums = [2,4,-2], k = 5
Output: 2
Explanation: All the possible subsequence sums that we can obtain are the following sorted in decreasing order:
- 6, 4, 4, 2, 2, 0, 0, -2.
The 5-Sum of the array is 2.

Example 2:

Input: nums = [1,-2,3,4,-10,12], k = 16
Output: 10
Explanation: The 16-Sum of the array is 10.

Constraints:
n == nums.length
1 <= n <= 10^5
-10^9 <= nums[i] <= 10^9
1 <= k <= min(2000, 2^n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long kSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> ans;
        priority_queue<pair<long long, long long>> pq;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                sum += nums[i];
            }
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        pq.push({sum - nums[0], 0});
        ans.push_back(sum);
        while (ans.size() < k)
        {
            int val = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            ans.push_back(val);
            if (index + 1 < n)
            {
                pq.push({val + nums[index] - nums[index + 1], index + 1});
                pq.push({val - nums[index + 1], index + 1});
            }
        }
        return ans[k - 1];
    }
};