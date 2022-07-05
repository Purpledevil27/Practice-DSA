// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

/*You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer
array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

Example 1:

Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.

Example 2:

Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.

Constraints:

1 <= n <= 10^5
0 <= edges.length <= 2 * 10^5
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated edges.
*/

#include <bits/stdc++.h>
using namespace std;

// Using DFS method
class Solution
{
public:
    void dfs(int i, long long &count, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
    {
        visited[i] = 1;
        count++;
        for (auto node : adj[i])
        {
            if (!visited[node])
            {
                dfs(node, count, adj, visited);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        for (auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        long long ans = ((long)(n) * (n - 1)) / 2;
        vector<bool> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                long long count = 0;
                dfs(i, count, adj, visited);
                ans -= ((long)(count) * (count - 1)) / 2;
            }
        }
        return ans;
    }
};

// Using Union Find by Rank
class UnionFind
{
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

public:
    UnionFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find_parent(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return find_parent(parent[x]);
    }

    void unify(int i, int j)
    {
        int parent_i = find_parent(i);
        int parent_j = find_parent(j);

        if (parent_i == parent_j)
        {
            return;
        }

        if (rank[parent_i] > rank[parent_j])
        {
            parent[parent_j] = parent_i;
            rank[parent_i] += rank[parent_j];
        }
        else
        {
            parent[parent_i] = parent_j;
            rank[parent_j] += rank[parent_i];
        }
    }
    int findConnected(int node)
    {
        return rank[find_parent(node)];
    }
    /*void o(int n){
        for(int i=0;i<n;i++){
            cout << "rank: "<<rank[i] << endl;
            cout << "parent: " <<parent[i] << endl;
        }
    }*/
};

class Solution
{
public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        UnionFind uf(n);
        for (auto i : edges)
        {
            uf.unify(i[0], i[1]);
        }
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            cout << uf.findConnected(i) << endl;
            res += n - uf.findConnected(i);
        }

        // uf.o(n);
        return res >> 1;
    }
};