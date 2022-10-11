// https://leetcode.com/problems/number-of-provinces/

/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
s
Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/

#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    vector<int> rank;
    vector<int> parent;

public:
    UnionFind(int const &n)
    {
        rank.resize(n, 0);
        parent.resize(n, -1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int const &x)
    {
        return parent[x] == x ? x : findParent(parent[x]);
    }

    void Union(int x, int y)
    {
        int px = findParent(x);
        int py = findParent(y);
        if (px == py)
        {
            return;
        }
        if (rank[px] < rank[py])
        {
            swap(px, py);
        }
        parent[py] = px;
        if (rank[px] == rank[py])
        {
            rank[px]++;
        }
    }

    int getProvinces()
    {
        unordered_map<int, int> m;
        for (auto &i : parent)
        {
            int p = findParent(i);
            if (m.count(p) == 0)
            {
                m[p]++;
            }
        }
        return m.size();
    }
};

class Solution
{

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();

        UnionFind uf(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (isConnected[i][j] == 1)
                {
                    uf.Union(i, j);
                }
            }
        }

        int ans = uf.getProvinces();

        return ans;
    }
};