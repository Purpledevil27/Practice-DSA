// https://leetcode.com/problems/permutations-ii/

/*Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output: [[1,1,2], [1,2,1], [2,1,1]]

Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Constraints:
1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
    vector<vector<int>> ans;
    void solve(vector<int> &nums, vector<int> &v, vector<int> &vis)
    {
        if (v.size() == nums.size())
        {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (vis[i])
                continue;

            v.push_back(nums[i]);
            vis[i] = 1;
            solve(nums, v, vis);
            vis[i] = 0;
            v.pop_back();

            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                ++i;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> vis(nums.size() + 1, 0);
        vector<int> v;
        solve(nums, v, vis);
        return ans;
    }
};

// Approach #2
class Solution
{
    vector<vector<int>> ans;
    void solve(vector<int> &nums, vector<int> &v, vector<int> &vis)
    {
        if (v.size() == nums.size())
        {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && vis[i - 1])
            {
                continue;
            }
            if (!vis[i])
            {
                v.push_back(nums[i]);
                vis[i] = 1;
                solve(nums, v, vis);
                vis[i] = 0;
                v.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> vis(nums.size() + 1, 0);
        vector<int> v;
        solve(nums, v, vis);
        return ans;
    }
};

// Approach #3
class Solution
{
public:
    void permute(vector<int> nums, int idx, vector<vector<int>> &res)
    {
        if (idx == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++)
        {
            if (i > idx && nums[i] == nums[idx])
                continue;
            swap(nums[idx], nums[i]);
            permute(nums, idx + 1, res);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        permute(nums, 0, res);
        return res;
    }
};