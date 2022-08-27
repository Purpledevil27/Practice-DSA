// https://leetcode.com/problems/maximal-rectangle/

/*Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = [["0"]]
Output: 0

Example 3:

Input: matrix = [["1"]]
Output: 1

Constraints:
rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

#include <bits/stdc++.h>
using namespace std;

// Similar to largest rectangle in histograms
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int h = 0, w = 0, ans = 0;
        vector<int> height(col + 1, 0);

        for (int i = 0; i < row; ++i)
        {
            stack<int> s;
            for (int j = 0; j <= col; ++j)
            {
                // set value
                if (j < col)
                {
                    if (matrix[i][j] == '1')
                        height[j] += 1;
                    else
                        height[j] = 0;
                }

                // compute area
                while (!s.empty() && height[s.top()] >= height[j])
                {
                    h = height[s.top()];
                    s.pop();
                    w = s.empty() ? j : j - s.top() - 1;
                    if (h * w > ans)
                        ans = h * w;
                }

                s.push(j);
            }
        }

        return ans;
    }
};