// https://leetcode.com/problems/critical-connections-in-a-network/
// https://www.geeksforgeeks.org/bridge-in-a-graph/

/*There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi.
Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

Example 1:

Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]

Constraints:
2 <= n <= 10^5
n - 1 <= connections.length <= 10^5
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void find(vector<int> adj[], int u, vector<int> &id, vector<int> &low, int &time, int parent, vector<vector<int>> &ans)
    {
        // Initialize id and low value
        id[u] = low[u] = ++time;

        // Going through all the neighbours of the node
        for (auto v : adj[u])
        {
            if (id[v] == -1)
            {
                // if node is not visited then recur it
                find(adj, v, id, low, time, u, ans);

                low[u] = min(low[u], low[v]);
                if (low[v] > id[u])
                {
                    ans.push_back({u, v});
                }
            }
            else if (v != parent)
            {
                low[u] = min(low[u], id[v]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto i : connections)
        {
            adj[i[1]].push_back(i[0]);
            adj[i[0]].push_back(i[1]);
        }
        vector<int> id(n, -1), low(n, INT_MAX);
        vector<vector<int>> ans;
        int time = 0, parent = -1;

        for (int i = 0; i < n; i++)
        {
            if (id[i] == -1)
            {
                find(adj, i, id, low, time, parent, ans);
            }
        }

        return ans;
    }
};