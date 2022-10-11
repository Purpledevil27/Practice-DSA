// https://leetcode.com/problems/max-consecutive-ones-iii/

/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            int t = 0, ans = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                {
                    ans = max(t, ans);
                    t = 0;
                }
                else
                {
                    t++;
                }
            }
            return ans = max(t, ans);
            ;
        }
        int start = 0, end = 0;
        int t = 0, ans = INT_MIN;
        while (end < nums.size())
        {
            if (nums[end] == 1)
            {
                t++;
            }
            else if (k > 0 && nums[end] == 0)
            {
                t++;
                k--;
            }
            else if (k == 0 && nums[end] == 0)
            {
                while (!k && start <= end)
                {
                    if (nums[start] == 0)
                    {
                        k++;
                        t--;
                    }
                    else
                    {
                        t--;
                    }
                    start++;
                }
                t++;
                k--;
            }
            ans = max(t, ans);
            end++;
        }
        return ans;
    }
};