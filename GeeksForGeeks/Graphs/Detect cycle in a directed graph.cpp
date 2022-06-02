// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/#
// https://www.cdn.geeksforgeeks.org/topological-sorting-indegree-based-solution/

/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V
denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed
graph contains a cycle or not.

Example 1:

Input:
6 6
5 3
3 1
1 2
2 4
0 4
4 5

Output:
1

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)

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
    // Function to detect cycle in a directed graph.
    bool find(vector<bool> &directed, vector<int> adj[], bool *visited, int i)
    {
        bool ans = false;
        visited[i] = true;
        directed[i] = true;
        for (auto j : adj[i])
        {
            if (!visited[j])
            {
                ans = find(directed, adj, visited, j);
                if (ans)
                {
                    return true;
                }
            }
            else if (directed[j])
            {
                return true;
            }
        }
        directed[i] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        vector<bool> directed(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool ans = find(directed, adj, visited, i);
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends