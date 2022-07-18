// https://leetcode.com/problems/spiral-matrix/

/*Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int count = row * col;
        vector<int> ans;

        int i = 0, j = 0, step = 0;

        // if count == 0, that means that we have covered all the cells
        while (count > 0)
        {
            // we will move to the top - rightmost for loop 1
            while (j < col - step && count > 0)
            {
                ans.push_back(matrix[i][j]);
                j++;
                count--;
            }
            // adjusting the positions for the next line
            j--;
            i++;

            // moving to the bottom rightmost for loop 1
            while (i < row - step && count > 0)
            {
                ans.push_back(matrix[i][j]);
                i++;
                count--;
            }
            // adjusting the positions for the next line
            i--;
            j--;

            // moving to the bottom leftmost for loop 1
            while (j >= step && count > 0)
            {
                ans.push_back(matrix[i][j]);
                j--;
                count--;
            }
            // adjusting the positions for the next line
            j++;
            i--;

            // moving back to the (top-1) leftmost i.e. not going to (0,0) again, but stopping at (1,0)
            while (i > step && count > 0)
            {
                ans.push_back(matrix[i][j]);
                i--;
                count--;
            }
            // adjusting the positions for the next line
            i++;
            j++;

            // step will take care of how many side to ignore for every loop. i.e. in the next step, it will not move to the rightmost or till the bottom, it will at stop one side earlier in the next loop
            step++;
        }
        return ans;
    }
};

int main()
{
    int n, m;
    cin >> m >> n;
    int x = 1;
    vector<vector<int>> v(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v[i][j] = x;
            x++;
        }
    }
    Solution obj;
    vector<int> ans = obj.spiralOrder(v);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}