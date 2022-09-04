// https://leetcode.com/problems/maximum-rows-covered-by-columns/

/*You are given a 0-indexed m x n binary matrix mat and an integer cols, which denotes the number of columns you must choose.

A row is covered by a set of columns if each cell in the row that has a value of 1 also lies in one of the columns of the chosen set.

Return the maximum number of rows that can be covered by a set of cols columns.

Example 1:

Input: mat = [[0,0,0],[1,0,1],[0,1,1],[0,0,1]], cols = 2
Output: 3
Explanation:
As shown in the diagram above, one possible way of covering 3 rows is by selecting the 0th and 2nd columns.
It can be shown that no more than 3 rows can be covered, so we return 3.

Example 2:

Input: mat = [[1],[0]], cols = 1
Output: 2
Explanation:
Selecting the only column will result in both rows being covered, since the entire matrix is selected.
Therefore, we return 2.

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 12
mat[i][j] is either 0 or 1.
1 <= cols <= n
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void find(vector<vector<int>> &mat, int cols, int k, vector<int> &chosen, int &ans)
    {
        // base case
        if (cols == 0 || k == mat[0].size())
        {
            int temp = 0;
            // traverse through the matrix
            for (int i = 0; i < mat.size(); i++)
            {
                bool isCov = true;
                for (int j = 0; j < mat[0].size(); j++)
                {
                    // if the column has value 1 but that column is not chosen then break, mark isCovered false.
                    if (mat[i][j] == 1 && !chosen[j])
                    {
                        isCov = false;
                        break;
                    }
                }
                if (isCov)
                    temp++;
            }
            ans = max(temp, ans);
            return;
        }
        // marking the kth column as chosen
        chosen[k] = 1;
        find(mat, cols - 1, k + 1, chosen, ans);
        // backtracking
        chosen[k] = 0;
        find(mat, cols, k + 1, chosen, ans);
    }

public:
    int maximumRows(vector<vector<int>> &mat, int cols)
    {
        int ans = INT_MIN;
        int n = mat[0].size();
        // create a vector to store the chosen column
        vector<int> chosen(n, 0);
        find(mat, cols, 0, chosen, ans);
        return ans;
    }
};