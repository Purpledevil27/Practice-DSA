// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

/*You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.

Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

// Better approach
class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        int ans = -1, sum[82] = {}; // 9 * 9
        for (int n : nums)
        {
            int currSum = 0;
            for (int nn = n; nn; nn /= 10)
                currSum += nn % 10;
            if (sum[currSum])
                ans = max(ans, sum[currSum] + n);
            sum[currSum] = max(sum[currSum], n);
        }
        return ans;
    }
};

// When you are new to coding - Solution
class Solution
{
    int getSum(int n)
    {
        int sum;
        for (sum = 0; n > 0; sum += n % 10, n /= 10)
            ;
        return sum;
    }

public:
    int maximumSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> v(n + 1);
        unordered_map<int, int> m;
        int index = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = getSum(nums[i]);
            if (m[sum] == 0)
            {
                m[sum] = index;
                v[index].push_back(nums[i]);
                index++;
            }
            else
            {
                for (auto it : m)
                {
                    if (it.first == sum)
                    {
                        int j = it.second;
                        v[j].push_back(nums[i]);
                    }
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < v.size(); i++)
        {
            sort(v[i].begin(), v[i].end());
        }

        for (int i = 0; i < v.size(); i++)
        {
            int t = v[i].size();
            if (t > 1)
            {
                ans = max(ans, v[i][t - 1] + v[i][t - 2]);
            }
        }
        return ans;
    }
};