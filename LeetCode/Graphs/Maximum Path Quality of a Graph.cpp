// https://leetcode.com/problems/maximum-path-quality-of-a-graph/

/*There is an undirected graph with n nodes numbered from 0 to n - 1 (inclusive). You are given a 0-indexed integer array values where values[i] is the value of the ith node.
You are also given a 0-indexed 2D integer array edges, where each edges[j] = [uj, vj, timej] indicates that there is an undirected edge between the nodes uj and vj, and it takes timej seconds to travel between the two nodes. Finally, you are given an integer maxTime.

A valid path in the graph is any path that starts at node 0, ends at node 0, and takes at most maxTime seconds to complete. You may visit the same node multiple times.
The quality of a valid path is the sum of the values of the unique nodes visited in the path (each node's value is added at most once to the sum).

Return the maximum quality of a valid path.

Note: There are at most four edges connected to each node.

Example 1:

Input: values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
Output: 75
Explanation:
One possible path is 0 -> 1 -> 0 -> 3 -> 0. The total time taken is 10 + 10 + 10 + 10 = 40 <= 49.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 0 + 32 + 43 = 75.

Example 2:

Input: values = [5,10,15,20], edges = [[0,1,10],[1,2,10],[0,3,10]], maxTime = 30
Output: 25
Explanation:
One possible path is 0 -> 3 -> 0. The total time taken is 10 + 10 = 20 <= 30.
The nodes visited are 0 and 3, giving a maximal path quality of 5 + 20 = 25.

Example 3:

Input: values = [1,2,3,4], edges = [[0,1,10],[1,2,11],[2,3,12],[1,3,13]], maxTime = 50
Output: 7
Explanation:
One possible path is 0 -> 1 -> 3 -> 1 -> 0. The total time taken is 10 + 13 + 13 + 10 = 46 <= 50.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 1 + 2 + 4 = 7.

Constraints:
n == values.length
1 <= n <= 1000
0 <= values[i] <= 10^8
0 <= edges.length <= 2000
edges[j].length == 3
0 <= uj < vj <= n - 1
10 <= timej, maxTime <= 100
All the pairs [uj, vj] are unique.
There are at most four edges connected to each node.
The graph may not be connected.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<vector<pair<int, int>>> &adj, vector<int> &values, int maxTime, vector<int> &vis, int &ans, int node, int q)
    {
        // marking the node as visited
        vis[node]++;
        // adding the quality if the node is visited first time - using ternary operator
        q += (vis[node] == 1 ? values[node] : 0);
        // if the current node is 0 then we check if is new maximum and store our answer
        if (node == 0)
        {
            ans = max(ans, q);
        }

        // checking for node neighbors/edges
        for (auto &i : adj[node])
        {
            // only calling if the maxTime is greater than zero
            if (maxTime - i.second >= 0)
            {
                solve(adj, values, maxTime - i.second, vis, ans, i.first, q);
            }
        }
        // backtracking
        vis[node]--;
    }

public:
    int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime)
    {
        int n = values.size();
        // create an adjacency list with edges and their respective weight
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0]; // node 1
            int v = edges[i][1]; // node 2
            int w = edges[i][2]; // respective weight
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        // at the beginning i was thinking that if we can move to different nodes any number of times, then how do we return
        // but then i realized that at some point, maxTime will be become less than or equal to zero and then we return
        // create a visited array to mark which node is already visited
        vector<int> vis(n);

        int ans = INT_MIN;
        // calling solve function
        solve(adj, values, maxTime, vis, ans, 0, 0);
        // return answer
        return ans;
    }
};