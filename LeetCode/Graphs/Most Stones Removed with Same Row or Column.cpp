// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

/*On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest
possible number of stones that can be removed.

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.

Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 10^4
No two stones are at the same coordinate point.

*/

#include <bits/stdc++.h>
using namespace std;

// Using Union by Rank & Path compression
class UnionFind
{
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

public:
    int count;

    UnionFind(vector<vector<int>> &stones)
    {
        for (auto i : stones)
        {
            int row = -(i[0] + 1);
            int col = (i[1] + 1);
            parent[row] = row;
            parent[col] = col;
        }
        count = parent.size();
    }

    int find_parent(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return find_parent(parent[x]);
    }

    void unify(int x, int y)
    {
        int parent_x = find_parent(x);
        int parent_y = find_parent(y);
        if (parent_x == parent_y)
        {
            return;
        }
        count--;

        if (rank[parent_x] < rank[parent_y])
        {
            swap(parent_x, parent_y);
        }
        parent[parent_y] = parent_x;
        if (rank[parent_x] == rank[parent_y])
        {
            rank[parent_x]++;
        }
    }
};

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        UnionFind uf(stones);

        for (auto i : stones)
        {
            int row = -(i[0] + 1);
            int col = (i[1] + 1);
            uf.unify(row, col);
        }

        return stones.size() - uf.count;
    }
};

// By making adjacency list and using DFS method
class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int i)
    {
        if (visited[i])
        {
            return;
        }
        visited[i] = true;
        for (auto node : adj[i])
        {
            dfs(adj, visited, node);
        }
    }

    void add_pair(vector<int> &x, vector<int> &y, map<pair<int, int>, int> &m, int i, vector<vector<int>> &stones)
    {
        x.emplace_back(stones[i][0]);
        y.emplace_back(stones[i][1]);
        pair<int, int> p{stones[i][0], stones[i][1]};
        m[p] = i;
    }

    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<vector<int>> adj(n);
        map<pair<int, int>, int> m;
        vector<int> x, y;

        for (int i = 0; i < n; i++)
        {
            if (find(x.begin(), x.end(), stones[i][0]) != x.end())
            {
                int index = find(x.begin(), x.end(), stones[i][0]) - x.begin();

                pair<int, int> p{x[index], y[index]};

                adj[m[p]].emplace_back(i);
                adj[i].emplace_back(m[p]);
            }
            if (find(y.begin(), y.end(), stones[i][1]) != y.end())
            {
                int index = find(y.begin(), y.end(), stones[i][1]) - y.begin();

                pair<int, int> p{x[index], y[index]};

                adj[m[p]].emplace_back(i);
                adj[i].emplace_back(m[p]);
            }
            add_pair(x, y, m, i, stones);
        }

        int count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(adj, visited, i);
            }
        }
        return n - count;
    }
};