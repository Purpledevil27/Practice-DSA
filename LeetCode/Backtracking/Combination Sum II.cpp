// https://leetcode.com/problems/combination-sum-ii/

/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: [[1,1,6],[1,2,5],[1,7],[2,6]]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: [[1,2,2],[5]]

Constraints:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{

    void backtrack(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &ans, int index)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        if (index == candidates.size() || target < 0)
            return;

        v.push_back(candidates[index]);
        backtrack(candidates, target - candidates[index], v, ans, index + 1);
        v.pop_back();

        while (index < candidates.size() - 1 && candidates[index] == candidates[index + 1])
            index++;

        backtrack(candidates, target, v, ans, index + 1);
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, const int &target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans, fin;
        vector<int> v;
        backtrack(candidates, target, v, ans, 0);
        return ans;
    }
};

// Approach #2
class Solution
{
public:
    void backtrack(int idx, int target, vector<int> &v, vector<vector<int>> &ans, vector<int> &candidates)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        for (int i = idx; i < candidates.size(); i++)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            v.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], v, ans, candidates);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        vector<vector<int>> ans;
        backtrack(0, target, v, ans, candidates);
        return ans;
    }
};