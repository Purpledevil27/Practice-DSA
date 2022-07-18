// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

/*Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output: 1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.

Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output: 2

Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as an input parameter and returns the total number of islands.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void help(vector<vector<char>> &grid, int r, int c, int i, int j)
    {
        if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j] != '1')
        {
            return;
        }

        grid[i][j] = '0';
        help(grid, r, c, i + 1, j);
        help(grid, r, c, i, j + 1);
        help(grid, r, c, i - 1, j);
        help(grid, r, c, i, j - 1);
        help(grid, r, c, i + 1, j - 1);
        help(grid, r, c, i + 1, j + 1);
        help(grid, r, c, i - 1, j + 1);
        help(grid, r, c, i - 1, j - 1);
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    help(grid, m, n, i, j);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends