// https://leetcode.com/problems/jump-game/

/*You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach
the last index.

Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5

*/

#include <bits/stdc++.h>
using namespace std;

// Front end
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int n = nums.size();
        if (n <= 1)
        {
            return true;
        }

        int j = n - 2, step = 1;
        bool ans = false;

        while (j >= 0)
        {
            int avail = nums[j--];
            if (avail >= step)
            {
                step = 1;
                ans = true;
            }
            else
            {
                ans = false;
                step++;
            }
        }
        return ans;
    }
};

// Front start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        for (int i = 0, step = 0; i < nums.size(); i++)
        {
            if (i > step)
                return false;
            step = max(step, i + nums[i]);
        }
        return true;
    }
};
