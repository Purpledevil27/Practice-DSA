//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    bool isSafe(bool graph[101][101], int vertex_color[], int color, int currNode, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (vertex_color[i] == color && graph[currNode][i])
                return false;
        }
        return true;
    }

    bool backtrack(bool graph[101][101], int vertex_color[], int m, int n, int currNode)
    {
        if (currNode == n)
            return true;
        for (int color = 1; color <= m; color++)
        {
            if (isSafe(graph, vertex_color, color, currNode, n))
            {
                vertex_color[currNode] = color;
                if (backtrack(graph, vertex_color, m, n, currNode + 1))
                    return true;
                // Backtracking
                vertex_color[currNode] = 0;
            }
        }
        return false;
    }

public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        int vertex_color[n] = {0};
        return backtrack(graph, vertex_color, m, n, 0);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends