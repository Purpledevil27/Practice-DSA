// https://leetcode.com/problems/cheapest-flights-within-k-stops/

/*There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation: The graph is shown above. The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Example 2:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation: The graph is shown above. The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Example 3:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation: The graph is shown above. The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.

Constraints:
1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 10^4
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/

#include <bits/stdc++.h>
using namespace std;

// BFS
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        // create a adjancent list
        for (auto &i : flights)
        {
            adj[i[0]].emplace_back(i[1], i[2]);
        }
        // distance vector for distances from source to different nodes.
        vector<int> distance(n, INT_MAX);
        // assign the source distance as zero
        distance[src] = 0;
        // a queue with path as {distance and source}
        queue<pair<int, int>> q;
        q.push({0, src});
        int steps = 0;
        // do bfs while queue is not empty or under we move k stops
        while (!q.empty() && steps < k + 1)
        {
            int size = q.size();
            while (size--)
            {
                auto p = q.front();
                q.pop();
                int dist = p.first, prev = p.second;
                // find the neighbor city
                for (auto &i : adj[prev])
                {
                    int v = i.first, wt = i.second;
                    // check if it is the one minimum cost
                    int cost = dist + wt;
                    if (cost > distance[v])
                        continue;
                    // else update cost and push element to queue
                    distance[v] = cost;
                    q.push({distance[v], v});
                }
            }
            // increment the step with one as we move 1 step every while loop
            steps++;
        }
        // return -1 if we cannot reach the destination city within the k stops else return the minimum cost
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};

// Bellman-ford algo
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        for (int i = 0; i <= k; i++)
        {
            vector<int> temp = distance;
            for (auto &j : flights)
            {
                int source = j[0], destination = j[1], cost = j[2];
                if (distance[source] != INT_MAX && temp[destination] > distance[source] + cost)
                {
                    temp[destination] = distance[source] + cost;
                }
            }
            distance = temp;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
