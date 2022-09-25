// https://practice.geeksforgeeks.org/problems/queries-on-a-matrix0443/1

/*You are given a matrix of dimension n*n. All the cells are initially, zero. You are given Q queries, which contains 4 integers a b c d where (a,b) is the TOP LEFT cell and (c,d) is the Bottom Right cell of a submatrix.
Now, all the cells of this submatrix have to be incremented by one. After all the Q queries have been performed. Your task is to find the final resulting Matrix.
Note : Zero-Based Indexing is used for cells of the matrix.

Example 1:

Input: n = 6, q = 6,
Queries = {
{4,0,5,3},
{0,0,3,4},
{1,2,1,2},
{1,1,2,3},
{0,0,3,1},
{1,0,2,4}}.
Output:
2 2 1 1 1 0
3 4 4 3 2 0
3 4 3 3 2 0
2 2 1 1 1 0
1 1 1 1 0 0
1 1 1 1 0 0

Your Task:
You don't need to read or print anything. Your task is to complete the function solveQueries() which takes n and Queries and input parameter and returns a matrix after performing all the queries.


Expected Time Complexity: O(n^2)
Expected Space Complexity: O(n^2)

Constraints:
1 <= n <= 1000
0 <= a <= c < n
0 <= b <= d < n
1 <= No. of Queries <= 1000
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries)
    {
        // Code here
        vector<vector<int>> vec(n, vector<int>(n, 0));
        for (auto v : Queries)
        {
            int a = v[0];
            int b = v[1];
            int c = v[2];
            int d = v[3];

            for (int i = a; i <= c; i++)
            {
                vec[i][b]++;
            }
            if (d + 1 < n)
            {
                for (int i = a; i <= c; i++)
                {
                    vec[i][d + 1]--;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                vec[i][j] = vec[i][j - 1] + vec[i][j];
            }
        }
        return vec;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++)
        {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++)
                cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends