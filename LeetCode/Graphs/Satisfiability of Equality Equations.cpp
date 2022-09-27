// https://leetcode.com/problems/satisfiability-of-equality-equations/

/*You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.

Example 2:

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

Constraints:
1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] is a lowercase letter.
equations[i][1] is either '=' or '!'.
equations[i][2] is '='.
equations[i][3] is a lowercase letter.
*/

#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind()
    {
        parent.resize(26, 0);
        rank.resize(26, 0);
        for (int i = 0; i < 26; i++)
        {
            parent[i] = i;
        }
    }
    int findParent(int const &x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return findParent(parent[x]);
    }

    void dounion(char const &xc, char const &yc)
    {
        int x = (int)xc - 97, y = (int)yc - 97;
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
    bool find(int const &x, int const &y)
    {
        return findParent(x) != findParent(y);
    }
};

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        UnionFind u;
        // Making groups of equal elements
        for (auto it : equations)
        {
            if (it[1] == '=')
            {
                u.dounion(it[0], it[3]);
            }
        }
        // checking if an unequal elements is present in an equal group
        for (auto it : equations)
        {
            if (it[1] == '!')
            {
                if (!u.find((int)it[0] - 97, (int)it[3] - 97))
                {
                    return false;
                };
            }
        }
        return true;
    }
};