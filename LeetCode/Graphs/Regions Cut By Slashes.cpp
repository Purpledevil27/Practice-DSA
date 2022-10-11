// https://leetcode.com/problems/regions-cut-by-slashes/

/*An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

Example 1:

Input: grid = [" /","/ "]
Output: 2

Example 2:

Input: grid = [" /","  "]
Output: 1

Example 3:

Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.

Constraints:
n == grid.length == grid[i].length
1 <= n <= 30
grid[i][j] is either '/', '\', or ' '.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int count = 0, n;
    vector<int> parent;

    int findParent(int const &x)
    {
        return parent[x] == x ? x : findParent(parent[x]); // return parent
    }

    void unify(int const &x, int const &y)
    {
        int px = findParent(x); // find parent
        int py = findParent(y); // find parent
        if (px != py)
        {
            parent[py] = px;
            count--; // decrement one from the total number of polygons since two of them are contiguous now.
        }
    }

    int getIndex(int const &i, int const &j, int const &k)
    {
        return (i * n + j) * 4 + k;
    }

public:
    int regionsBySlashes(vector<string> &grid)
    {
        n = grid.size();   // assign size of grid to n
        count = n * n * 4; // this is the total number of polygons possible
        for (int i = 0; i < count; i++)
        {
            parent.push_back(i); // initialise parent vector
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // the square is divided into four corners ❌ top - 0, right - 1, bottom - 2, left - 3
                // these two pair of triangles are supposed to be contiguous
                if (i > 0)
                    unify(getIndex(i - 1, j, 2), getIndex(i, j, 0));
                if (j > 0)
                    unify(getIndex(i, j - 1, 1), getIndex(i, j, 3));
                // if it is  "\\" or " " then apply these operations
                if (grid[i][j] != '/')
                {
                    unify(getIndex(i, j, 0), getIndex(i, j, 1));
                    unify(getIndex(i, j, 2), getIndex(i, j, 3));
                }
                // if it is  "/" or " " then apply these operations
                if (grid[i][j] != '\\')
                {
                    unify(getIndex(i, j, 0), getIndex(i, j, 3));
                    unify(getIndex(i, j, 2), getIndex(i, j, 1));
                }
            }
        }
        return count;
    }
};