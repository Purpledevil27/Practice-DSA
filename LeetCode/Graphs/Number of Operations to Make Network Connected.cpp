// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

/* This is solved using DFS approach. Similarly BFS approach can also be used. For storing edges, adjacency matrix exceeds time
limit but adjacency list does not .Can you find a approach using UNION FIND ?

*/
/*There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where
connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly
or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers,
and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible,
return -1.

Example 1:

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1

Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

Example 2:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1

Explanation: There are not enough cables.

Constraints:

1 <= n <= 10^5
1 <= connections.length <= min(n * (n - 1) / 2, 10^5)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &edges, vector<bool> &visited, int sv, int n)
    {
        visited[sv] = true;

        for (auto i : edges[sv])
        {
            if (!visited[i])
            {
                dfs(edges, visited, i, n);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int numcables = connections.size();

        if (numcables < n - 1)
        {
            return -1;
        }
        vector<vector<int>> edges(n);
        vector<bool> visited(n, false);
        for (auto i : connections)
        {
            edges[i[0]].push_back(i[1]);
            edges[i[1]].push_back(i[0]);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(edges, visited, i, n);
            }
        }
        return count - 1;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> computerconnected(n);

    for (int i = 0; i < n; i++)
    {
        int f, s;
        cin >> f >> s;
        computerconnected[i][0] = f;
        computerconnected[i][1] = s;
    }

    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    Solution obj;
    cout << obj.makeConnected(n, computerconnected);

    return 0;
}