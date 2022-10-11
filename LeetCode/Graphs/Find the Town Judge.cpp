// https://leetcode.com/problems/find-the-town-judge/

/*In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2

Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3

Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

Constraints:
1 <= n <= 1000
0 <= trust.length <= 10^4
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto &i : trust)
        {
            adj[i[0] - 1].push_back(i[1] - 1);
            indegree[i[1] - 1]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() == 0 && indegree[i] == n - 1)
            {
                return i + 1;
            }
        }
        return -1;
    }
};

// Approach #2
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &a)
    {
        vector<bool> v(n + 1, true);
        for (int i = 0; i < a.size(); i++)
            v[a[i][0]] = false;
        int res = -1;
        for (int i = 1; i <= n; i++)
        {
            if (v[i])
            {
                if (res != -1)
                    return -1;
                res = i;
            }
        }
        int cnt = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i][1] == res)
                cnt++;
        }
        if (cnt == n - 1)
            return res;
        return -1;
    }
};