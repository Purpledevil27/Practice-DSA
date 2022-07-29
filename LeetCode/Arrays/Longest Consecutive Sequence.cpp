// https://leetcode.com/problems/longest-consecutive-sequence/

/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

// Using HashSet - O(N)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> m(nums.begin(), nums.end());
        int max_len = 1, cur_len = 0;
        for (auto &i : m)
        {
            if (m.find(i - 1) == m.end())
            {
                cur_len = 1;
                int nex_num = i + 1;
                while (m.find(nex_num) != m.end())
                {
                    cur_len++;
                    nex_num++;
                }
                max_len = max(max_len, cur_len);
            }
        }
        return max_len;
    }
};