// https://leetcode.com/problems/evaluate-division/

/*You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation:
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]

Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]

Constraints:
1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    double d;
    bool found = false;
    void dfs(string start, string const &end, map<string, vector<pair<string, double>>> &m, unordered_map<string, int> vis)
    {
        if (start == end)
        {
            found = true;
            return;
        }
        if (vis[start])
        {
            return;
        }
        vis[start]++;
        vector<pair<string, double>> vv = m[start];
        for (auto &v : m[start])
        {
            d *= v.second;
            dfs(v.first, end, m, vis);
            if (found)
                return;
            d /= v.second;
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int n = equations.size();
        map<string, vector<pair<string, double>>> m;
        for (int i = 0; i < equations.size(); i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            m[u].push_back({v, w});
            double ww = 1 / w;
            m[v].push_back({u, ww});
        }
        unordered_map<string, int> vis;
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            string start = queries[i][0], end = queries[i][1];
            if (m.count(start) == 0 || m.count(end) == 0)
            {
                ans.push_back(-1);
                continue;
            }
            d = 1;
            found = false;
            dfs(start, end, m, vis);
            found ? ans.push_back(d) : ans.push_back(-1);
        }
        return ans;
    }
};