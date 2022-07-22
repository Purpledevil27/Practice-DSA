// https://leetcode.com/problems/permutations/

/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    void permute(vector<int> &nums, int idx, vector<vector<int>> &res)
    {
        if (idx == nums.size())
            res.push_back(nums);
        for (int i = idx; i < nums.size(); ++i)
        {
            swap(nums[idx], nums[i]);
            permute(nums, idx + 1, res);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        permute(nums, 0, res);
        return res;
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> vis(nums.size() + 1, 0);
        vector<int> v;
        solve(nums, v, vis);
        return ans;
    }
};