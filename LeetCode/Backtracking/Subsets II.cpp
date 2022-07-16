// https://leetcode.com/problems/subsets-ii/

/*Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
    void backtrack(vector<int> &nums, int i, int n, vector<int> &v, vector<vector<int>> &ans)
    {
        ans.push_back(v);
        for (int j = i; j < n; j++)
        {
            if (j != i && nums[j] == nums[j - 1])
                continue;
            v.push_back(nums[j]);
            backtrack(nums, j + 1, n, v, ans);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        backtrack(nums, 0, n, v, ans);
        return ans;
    }
};

// Approach #2
class Solution
{
    void bt(int index, vector<vector<int>> &ans, vector<int> &v, vector<int> const &nums, bool insert)
    {
        /*for(auto i:v){
            cout << i << " ";
        }cout <<endl;*/
        if (insert)
            ans.push_back(v);
        if (index >= nums.size())
        {
            return;
        }
        v.push_back(nums[index]);
        insert = true;
        bt(index + 1, ans, v, nums, insert);
        // BackTrack
        v.pop_back();
        insert = false;
        while (index < nums.size() - 1 && nums[index] == nums[index + 1])
            index++;
        bt(index + 1, ans, v, nums, insert);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> v;
        vector<vector<int>> ans;
        bool insert = true;
        bt(0, ans, v, nums, insert);
        return ans;
    }
};