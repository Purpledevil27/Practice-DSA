// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

/*There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a
bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most
distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

Example 1:

Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph.
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2]
City 1 -> [City 0, City 2, City 3]
City 2 -> [City 0, City 1, City 3]
City 3 -> [City 1, City 2]
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

Example 2:

Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph.
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1]
City 1 -> [City 0, City 4]
City 2 -> [City 3, City 4]
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3]
The city 0 has 1 neighboring city at a distanceThreshold = 2.

Constraints:

2 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti, distanceThreshold <= 10^4
All pairs (fromi, toi) are distinct.

*/
#include <bits/stdc++.h>
using namespace std;

// Using Floyd Warshall Algorithm
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> city(n, vector<int>(n, INT_MAX));
        for (auto i : edges)
        {
            city[i[0]][i[1]] = i[2];
            city[i[1]][i[0]] = i[2];
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                        continue;
                    if (city[i][k] != INT_MAX && city[k][j] != INT_MAX && city[i][j] > city[i][k] + city[k][j])
                    {
                        city[i][j] = city[i][k] + city[k][j];
                    }
                }
            }
        }
        int ans = -1, c = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int nc = 0;
            for (int j = 0; j < n; j++)
            {
                if (city[i][j] != INT_MAX && city[i][j] <= distanceThreshold)
                {
                    nc++;
                }
            }
            if (nc <= c)
            {
                ans = i;
                c = nc;
            }
        }
        return ans;
    }
};

// Using Dijkstra Algorithm - NlogN
class Solution
{
public:
    void dijkstra(int n, vector<vector<pair<int, int>>> &edge, int const &source, int const &distanceThreshold, int &ans, int &num)
    {
        vector<int> distance(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distance[source] = 0;
        pq.push({0, source});
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            for (auto &i : edge[prev])
            {
                if (distance[i.first] > dist + i.second)
                {
                    distance[i.first] = dist + i.second;
                    pq.push({distance[i.first], i.first});
                }
            }
        }
        int city = 0;
        for (int i = 0; i < n; i++)
        {
            if (distance[i] != 0 && distance[i] <= distanceThreshold)
            {
                city++;
            }
        }
        if (num >= city)
        {
            num = city;
            ans = max(ans, source);
        }
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> edge(n);
        int ans = INT_MIN, num = INT_MAX;
        for (auto i : edges)
        {
            edge[i[0]].push_back({i[1], i[2]});
            edge[i[1]].push_back({i[0], i[2]});
        }
        for (int i = 0; i < n; i++)
        {
            dijkstra(n, edge, i, distanceThreshold, ans, num);
        }
        return ans;
    }
};