// https://leetcode.com/problems/rotate-image/

/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix[0].size();
        for (int i = 0; i < n / 2 + n % 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};

// Approach #2
class Solution
{
public:
    void rotate(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int size = n, start = 0, end = n;
        while (size > 1)
        {
            int unique_ele = size - 1, k = 0;
            int i = start, j = start, step = 4 * unique_ele;
            vector<int> d(unique_ele);
            for (int p = end - 1; p > start; p--)
                d[k++] = grid[p][j];
            k = 0;
            while (step > 0)
            {
                while (j < end && step > 0)
                {
                    swap(grid[i][j], d[k++]);
                    if (k == unique_ele)
                        k = 0;
                    j++;
                    step--;
                }
                j--;
                i++;
                while (i < end && step > 0)
                {
                    swap(grid[i][j], d[k++]);
                    if (k == unique_ele)
                        k = 0;
                    i++;
                    step--;
                }
                i--;
                j--;
                while (j >= start && step > 0)
                {
                    swap(grid[i][j], d[k++]);
                    if (k == unique_ele)
                        k = 0;
                    j--;
                    step--;
                }
                j++;
                i--;
                while (i > start && step > 0)
                {
                    swap(grid[i][j], d[k++]);
                    if (k == unique_ele)
                        k = 0;
                    i--;
                    step--;
                }
            }
            size -= 2;
            start++;
            end--;
        }
    }
};

// Approach #4
class Solution
{
public:
    void rotate(vector<vector<int>> &mat)
    {
        int n = mat.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) // first swap then reverse each row
                swap(mat[i][j], mat[j][i]);
        for (int i = 0; i < n; i++)
            reverse(mat[i].begin(), mat[i].end());
    }
};