// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/#

/*Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

Your task:
You dont need to read input or print anything. Your task is to complete the function dfsOfGraph() which takes the integer V
denoting the number of vertices and adjacency list as input parameters and returns  a list containing the DFS traversal of the
graph starting from the 0th vertex from left to right according to the graph.

Input:
1
5 4
0 1
0 2
0 4
4 3

Output: 0 1 2 4 3
Explanation:
0 is connected to 1, 2, 4.
1 is connected to 0.
2 is connected to 0.
3 is connected to 4.
4 is connected to 0, 3.
so starting from 0, it will go to 1 then 2
then 4, and then from 4 to 3.
Thus dfs will be 0 1 2 4 3.

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)

Constraints:
1 ≤ V, E ≤ 10^4

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void help(int V, vector<int> adj[], int sv, vector<bool> &visited, vector<int> &ans)
    {

        ans.push_back(sv);
        visited[sv] = true;
        for (auto i : adj[sv])
        {
            if (!visited[i])
            {
                help(V, adj, i, visited, ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        vector<bool> visited(V, false);
        help(V, adj, 0, visited, ans);
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends