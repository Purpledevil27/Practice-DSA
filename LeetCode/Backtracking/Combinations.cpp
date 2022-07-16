// https://leetcode.com/problems/combinations/

/*Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output: [[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]
Example 2:

Input: n = 1, k = 1
Output: [[1]]

Constraints:
1 <= n <= 20
1 <= k <= n
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void bt(const int &n, int k, int num, vector<vector<int>> &ans, vector<int> &v)
    {
        if (k == 0)
        {
            ans.push_back(v);
            return;
        }
        for (int i = num; i <= n; i++)
        {
            if (k > n - i + 1)
                break;
            v.push_back(i);
            bt(n, k - 1, i + 1, ans, v);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> v;
        vector<vector<int>> ans;
        bt(n, k, 1, ans, v);
        return ans;
    }
};

class Solution
{
    void bt(const int &n, int k, int num, vector<vector<int>> &ans, vector<int> &v)
    {
        if (k == 0)
        {
            ans.push_back(v);
            return;
        }
        if (num > n)
        {
            return;
        }
        if (k > n - num + 1)
            return;
        v.push_back(num);
        bt(n, k - 1, num + 1, ans, v);
        v.pop_back();
        bt(n, k, num + 1, ans, v);
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> v;
        vector<vector<int>> ans;
        bt(n, k, 1, ans, v);
        return ans;
    }
};