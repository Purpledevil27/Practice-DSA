// https://leetcode.com/problems/jump-game-ii/

/*You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [2,3,0,1,4]
Output: 2

Constraints:
1 <= nums.length <= 10^4
0 <= nums[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int cur = nums[0], mx = nums[0], steps = 1, n = nums.size();
        // no steps required
        if (n == 1)
            return 0;
        for (int i = 1; i < n - 1; i++)
        {
            // update the maximum possible reach value
            if (nums[i] + i > mx)
            {
                mx = nums[i] + i;
            }
            // when reached the cur max possible reach, update the cur and increase the step making a jump.
            if (cur == i)
            {
                steps++;
                cur = mx;
            }
        }
        return steps;
    }
};