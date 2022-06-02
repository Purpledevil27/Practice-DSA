// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
// https://www.geeksforgeeks.org/range-based-loop-c/

/*Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.

Example 1:

Input:
5 5
0 4
1 2
1 4
2 3
3 4

Output:
1

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of
vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle
or not, return 1 if a cycle is present else return 0.

NOTE: The adjacency list denotes the edges of the graph where edges[i][0] and edges[i][1] represent an edge.

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 10^5

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool find(int V, vector<int> adj[], bool *visited, int i, int parent)
    {
        if (visited[i])
        {
            return true;
        }
        visited[i] = true;
        bool ans = false;
        for (auto j : adj[i])
        {
            if (j != parent)
            {
                ans = find(V, adj, visited, j, i);
                if (ans)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool ans = find(V, adj, visited, i, i);
                if (ans)
                {
                    return ans;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends