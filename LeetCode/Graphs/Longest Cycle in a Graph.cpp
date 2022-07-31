// https://leetcode.com/problems/longest-cycle-in-a-graph/

/*You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.

Example 1:

Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.

Example 2:

Input: edges = [2,-1,3,1]
Output: -1
Explanation: There are no cycles in this graph.

Constraints:
n == edges.length
2 <= n <= 10^5
-1 <= edges[i] < n
edges[i] != i
*/

#include <bits/stdc++.h>
using namespace std;

// idea of indexing nodes from Tarjan's algorithm. Obviously each node can have at most one "next" node, so a recursion is not needed.
// Simply track the path and label each node with an increamenting index until we meet one that already has an index. We then check if the index is in our current path and update the answer.
class Solution
{
public:
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size(), ans = -1;
        vector<int> idx(n);
        for (int i = 0, k = 1; i < n; i++)
        {
            int j = i, curk = k;
            while (j != -1 && !idx[j])
            {
                idx[j] = k++;
                j = edges[j];
            }
            if (j != -1 && idx[j] >= curk)
                ans = max(ans, k - idx[j]);
        }
        return ans;
    }
};

// Approach #2 - finding cycle in a graph
class Solution
{
    int find(vector<bool> &directed, vector<vector<int>> &adj, vector<bool> &visited, int i, vector<int> &v)
    {
        visited[i] = true;
        directed[i] = true;
        bool t = false;
        for (auto j : adj[i])
        {
            if (!visited[j])
            {
                v.push_back(j);
                t = find(directed, adj, visited, j, v);
                if (t)
                    return true;
                v.pop_back();
            }
            else if (directed[j])
            {
                v.push_back(j);
                return true;
            }
        }
        directed[i] = false;
        return false;
    }

    int cycle(vector<vector<int>> &adj, int const &v)
    {
        vector<bool> visited(v, false);
        vector<bool> directed(v, false);

        vector<int> vec;
        int ans = -1;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                vec.push_back(i);
                bool t = find(directed, adj, visited, i, vec);
                int j = -1, count = 0;
                if (t)
                {
                    while (j != vec[vec.size() - 1])
                    {
                        j = vec[count];
                        count++;
                    }
                    int s = vec.size();
                    ans = max(ans, s - count);
                }
                vec.clear();
            }
        }
        return ans;
    }

public:
    int longestCycle(vector<int> &edges)
    {
        vector<vector<int>> adj(edges.size());
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i] != -1)
                adj[i].push_back(edges[i]);
        }
        return cycle(adj, edges.size());
    }
};
