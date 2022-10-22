// https://leetcode.com/problems/frog-position-after-t-seconds/

/*Given an undirected tree consisting of n vertices numbered from 1 to n. A frog starts jumping from vertex 1. In one second, the frog jumps from its current vertex to another unvisited vertex if they are directly connected. The frog can not jump back to a visited vertex. In case the frog can jump to several vertices, it jumps randomly to one of them with the same probability. Otherwise, when the frog can not jump to any unvisited vertex, it jumps forever on the same vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi.

Return the probability that after t seconds the frog is on the vertex target. Answers within 10-5 of the actual answer will be accepted.

Example 1:

Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
Output: 0.16666666666666666
Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 probability to the vertex 2 after second 1 and then jumping with 1/2 probability to vertex 4 after second 2. Thus the probability for the frog is on the vertex 4 after 2 seconds is 1/3 * 1/2 = 1/6 = 0.16666666666666666.

Example 2:

Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
Output: 0.3333333333333333
Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 = 0.3333333333333333 probability to the vertex 7 after second 1.

Constraints:
1 <= n <= 100
edges.length == n - 1
edges[i].length == 2
1 <= ai, bi <= n
1 <= t <= 50
1 <= target <= n
*/

#include <bits/stdc++.h>
using namespace std;

// Using BFS
class Solution
{
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
        vector<vector<int>> adj(n + 1);
        for (auto &i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n + 1, false);
        queue<pair<int, double>> q;
        q.push({1, 1});
        t++;
        while (!q.empty() && t--)
        {

            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto temp = q.front();
                q.pop();
                vis[temp.first] = true;
                double child = (temp.first == 1) ? adj[temp.first].size() : adj[temp.first].size() - 1;
                if (temp.first == target)
                {
                    if (t == 0 || child == 0)
                        return temp.second;
                    else
                    {
                        return 0;
                    }
                }
                for (auto &k : adj[temp.first])
                {
                    if (!vis[k])
                    {
                        q.push({k, temp.second * (1 / child)});
                    }
                }
            }
        }
        return 0;
    }
};

// Using DFS
class Solution
{
public:
    double dfs(vector<int> adj[], int node, int t, int target, vector<int> &visited)
    {
        /*adj[node].size() == 1 --> condition for leaf vertex*/
        if (t == 0 || node != 1 && adj[node].size() == 1)
        {
            if (node == target)
                return 1.0;
            else
                return 0.0;
        }
        visited[node] = 1;
        double ans = 0.0;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                ans += dfs(adj, it, t - 1, target, visited);
            }
        }

        if (node == 1)
            return ans * 1.0 / (adj[node].size());
        return ans * 1.0 / (adj[node].size() - 1);
    }
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
        if (n == 1)
            return 1.0;
        vector<int> adj[n + 1];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n + 1, 0);
        return dfs(adj, 1, t, target, visited);
    }
};