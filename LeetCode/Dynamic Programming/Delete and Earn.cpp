// https://leetcode.com/problems/delete-and-earn/

// Similar to House Robber problem - https://leetcode.com/problems/house-robber/

/*You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.

Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.

Constraints:
1 <= nums.length <= 2 * 10^4
1 <= nums[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

// TC - O(N) & SC - O(N)
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        map<int, int> m;
        for (auto i : nums)
        {
            m[i] += i;
        }
        int curr = 0, pre = 0;
        for (auto &i : m)
        {
            if (m.find(i.first - 1) == m.end())
            {
                pre = curr;
                curr += i.second;
            }
            else
            {
                int temp = max(curr, pre + i.second);
                pre = curr;
                curr = temp;
            }
        }
        return curr;
    }
};

// Approach #2
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        auto mx = max_element(nums.begin(), nums.end());
        int len = *mx + 1, ans = 0;
        vector<int> mark(len);
        for (auto &num : nums)
            mark[num] += num;
        int curr = 0, pre = 0;
        for (int i = 0; i < len; i++)
        {
            int temp = max(pre + mark[i], curr);
            pre = curr;
            curr = temp;
        }
        return curr;
    }
};

// Approach #3
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        auto mx = max_element(nums.begin(), nums.end());
        int len = *mx + 1, ans = 0;
        vector<int> mark(len);
        for (auto &num : nums)
            mark[num] += num;
        vector<int> dp(len);
        dp[0] = mark[0];
        dp[1] = max(mark[1], dp[1]);
        for (int i = 2; i < len; i++)
        {
            dp[i] = max(dp[i - 2] + mark[i], dp[i - 1]);
        }
        return dp[len - 1];
    }
};