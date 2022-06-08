// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1/#
// https://www.geeksforgeeks.org/strongly-connected-components/

/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components
in the graph.

Example 1:

Input:
5 5
1 0
0 2
2 1
0 3
3 4

Output:
3

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).

Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ N-1
Sum of E over all testcases will not exceed 25*10^6

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void countSSC(vector<int> adj[], vector<bool> &visited, int i)
    {
        if (visited[i])
        {
            return;
        }
        visited[i] = true;
        for (auto p : adj[i])
        {
            countSSC(adj, visited, p);
        }
    }

    void dfs(vector<int> adj[], vector<bool> &visited, int n, int i, stack<int> &stack)
    {
        if (visited[i])
        {
            return;
        }

        visited[i] = true;
        for (auto node : adj[i])
        {
            dfs(adj, visited, n, node, stack);
        }
        stack.push(i);
    }

    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        stack<int> stack;
        for (int i = 0; i < V; i++)
        {
            dfs(adj, visited, V, i, stack);
        }
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        vector<int> adj2[V];
        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                adj2[j].push_back(i);
            }
        }

        int count = 0;
        while (!stack.empty())
        {
            int node = stack.top();
            stack.pop();
            if (!visited[node])
            {
                count++;
                countSSC(adj2, visited, node);
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends