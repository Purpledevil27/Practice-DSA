// https://leetcode.com/problems/number-of-arithmetic-triplets/

/*You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:

i < j < k,
nums[j] - nums[i] == diff, and
nums[k] - nums[j] == diff.
Return the number of unique arithmetic triplets.

Example 1:

Input: nums = [0,1,4,6,7,10], diff = 3
Output: 2
Explanation:
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3.

Example 2:

Input: nums = [4,5,6,7,8,9], diff = 2
Output: 2
Explanation:
(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.

Constraints:
3 <= nums.length <= 200
0 <= nums[i] <= 200
1 <= diff <= 50
nums is strictly increasing.
*/

#include <bits/stdc++.h>
using namespace std;

// O(N)
class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int cnt[201] = {}, res = 0;
        for (auto n : nums)
        {
            if (n >= 2 * diff)
                res += cnt[n - diff] && cnt[n - 2 * diff];
            cnt[n] = true;
        }
        return res;
    }
};

// Using Binary Search O(NlogN);
class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            int t = nums[i];
            int find1 = nums[i] + diff, find2 = nums[i] + (2 * diff);
            int u1 = lower_bound(nums.begin(), nums.end(), find1) - nums.begin();
            int u2 = lower_bound(nums.begin(), nums.end(), find2) - nums.begin();
            // cout << "find1 " << find1 << "u1 " << u1 <<  " find1 " << find2 << " u1 " << u2 << endl;
            if (u1 < n && u2 < n)
            {
                if (nums[u1] == find1 && nums[u2] == find2)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};