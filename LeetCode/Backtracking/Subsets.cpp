// https://leetcode.com/problems/subsets/

/*Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<int> &nums, vector<int> &v, vector<vector<int>> &ans, int start)
    {
        ans.push_back(v);
        if (nums.size() == start)
        {
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            v.push_back(nums[i]);
            solve(nums, v, ans, i + 1);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> v;
        vector<vector<int>> ans;
        solve(nums, v, ans, 0);
        return ans;
    }
};