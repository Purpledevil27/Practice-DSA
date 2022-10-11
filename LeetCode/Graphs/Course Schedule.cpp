// https://leetcode.com/problems/course-schedule/

/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &dir, int i)
    {
        if (dir[i])
        {
            return false;
        }
        if (vis[i])
        {
            return true;
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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for (auto &i : prerequisites)
        {
            adj[i[1]].push_back(i[0]);
        }
        // int index=0;
        // for(auto &i:adj){
        //     cout << index++ << " ";
        //     for(auto &j:i){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        vector<int> vis(n, 0);
        vector<int> dir(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && !dfs(adj, vis, dir, i))
            {
                return false;
            }
        }
        return true;
    }
};