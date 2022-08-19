// https://leetcode.com/problems/split-array-into-consecutive-subsequences/

/*You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.

A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).

Example 1:

Input: nums = [1,2,3,3,4,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,5] --> 1, 2, 3
[1,2,3,3,4,5] --> 3, 4, 5

Example 2:

Input: nums = [1,2,3,3,4,4,5,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
[1,2,3,3,4,4,5,5] --> 3, 4, 5

Example 3:

Input: nums = [1,2,3,4,4,5]
Output: false
Explanation: It is impossible to split nums into consecutive increasing subsequences of length 3 or more.

Constraints:
1 <= nums.length <= 10^4
-1000 <= nums[i] <= 1000
nums is sorted in non-decreasing order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        map<int, int> m;
        for (int &num : nums)
            ++m[num];
        vector<pair<int, int>> seqs; // pair: start, end
        for (auto &it : m)
        {
            int num = it.first, freq = it.second;
            int i = seqs.size() - 1;
            for (int j = 0; j < freq; ++j)
            {
                if (i >= 0 && seqs[i].second + 1 == num)
                {
                    seqs[i].second = num;
                    --i;
                }
                else
                {
                    seqs.push_back({num, num});
                }
            }
        }
        for (auto &p : seqs)
        {
            if (p.second - p.first < 2)
                return false;
        }
        return true;
    }
};