// https://leetcode.com/problems/course-schedule-ii/

/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*/

#include <bits/stdc++.h>
using namespace std;

// DFS and topological sort
class Solution
{
    void add(vector<vector<int>> &adj, vector<int> &vis, int i, vector<int> &ans)
    {
        if (vis[i])
            return;
        vis[i] = 1;
        for (auto &n : adj[i])
        {
            add(adj, vis, n, ans);
        }
        ans.push_back(i);
    }
    bool dfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &dir, int i)
    {
        if (dir[i])
        {
            return false;
        }
        dir[i] = 1;
        vis[i] = 1;
        for (auto &n : adj[i])
        {
            if (!dfs(adj, vis, dir, n))
            {
                return false;
            }
        }
        dir[i] = 0;
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = numCourses;
        vector<int> visited(n, 0), directed(n, 0);
        vector<vector<int>> adj(n);
        for (auto &i : prerequisites)
        {
            adj[i[0]].push_back(i[1]);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && !dfs(adj, visited, directed, i))
            {
                return {};
            }
        }
        visited.clear();
        visited.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                add(adj, visited, i, ans);
            }
        }
        return ans;
    }
};

// BFS and Indegree
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<int> adj[numCourses];
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        // store
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // indegree u -> v
        for (int i = 0; i < prerequisites.size(); i++)
        {
            indegree[prerequisites[i][0]]++;
        }
        // push into q,indegree having 0
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> result;
        // Simple BFS and keep storing indegree values equal to 0 into result vector
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto it : adj[v])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
            result.emplace_back(v);
        }
        // check case
        if (result.size() != numCourses)
            result.clear();
        return result;
    }
};