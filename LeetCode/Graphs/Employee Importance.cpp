// https://leetcode.com/problems/employee-importance/

/*You have a data structure of employee information, including the employee's unique ID, importance value, and direct subordinates' IDs.

You are given an array of employees employees where:

employees[i].id is the ID of the ith employee.
employees[i].importance is the importance value of the ith employee.
employees[i].subordinates is a list of the IDs of the direct subordinates of the ith employee.
Given an integer id that represents an employee's ID, return the total importance value of this employee and all their direct and indirect subordinates.

Example 1:

Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
Output: 11
Explanation: Employee 1 has an importance value of 5 and has two direct subordinates: employee 2 and employee 3.
They both have an importance value of 3.
Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.

Example 2:

Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
Output: -3
Explanation: Employee 5 has an importance value of -3 and has no direct subordinates.
Thus, the total importance value of employee 5 is -3.

Constraints:
1 <= employees.length <= 2000
1 <= employees[i].id <= 2000
All employees[i].id are unique.
-100 <= employees[i].importance <= 100
One employee has at most one direct leader and may have several subordinates.
The IDs in employees[i].subordinates are valid IDs.
*/

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

#include <bits/stdc++.h>
using namespace std;

// Approach #1 - Using hashmap
class Solution
{
public:
    void dfs(vector<Employee *> employees, int id, unordered_map<int, int> &map, int &op)
    {
        Employee *temp = employees[map[id]];
        op += temp->importance;
        for (int i : temp->subordinates)
            dfs(employees, i, map, op);
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < employees.size(); i++)
            map[employees[i]->id] = i;
        int op = 0;
        dfs(employees, id, map, op);
        return op;
    }
};

// Approach #2 - Using vector
class Solution
{
    void dfs(vector<pair<int, vector<int>>> &adj, vector<int> &vis, int i, int &ans)
    {
        if (vis[i])
            return;
        vis[i] = 1;
        ans += adj[i].first;
        for (auto &node : adj[i].second)
        {
            dfs(adj, vis, node, ans);
        }
    }

public:
    int getImportance(vector<Employee *> employees, int id)
    {
        vector<pair<int, vector<int>>> adj(2002);
        for (auto &i : employees)
        {
            adj[i->id] = {i->importance, i->subordinates};
        }
        int ans = 0;
        // vector<int> vis(2002, 0);
        // dfs(adj, vis, id, ans); // doing DFS
        // BFS
        queue<int> q;
        q.push(id);
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            ans += adj[f].first;
            for (auto &node : adj[f].second)
            {
                q.push(node);
            }
        }
        return ans;
    }
};