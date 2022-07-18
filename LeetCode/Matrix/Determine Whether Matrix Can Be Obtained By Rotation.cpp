// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

/*Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

Example 1:

Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.

Example 2:

Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.

Example 3:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.

Constraints:
n == mat.length == target.length
n == mat[i].length == target[i].length
1 <= n <= 10
mat[i][j] and target[i][j] are either 0 or 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findRotation(vector<vector<int>> &matrix, vector<vector<int>> &target)
    {
        for (int i = 0; i < 4; i++)
        {
            int n = matrix.size();
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
            if (matrix == target)
                return true;
        }
        return false;
    }
};

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        for (int i = 0; i < 4; i++)
        {
            int n = mat.size();
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++) // first swap then reverse each row
                    swap(mat[i][j], mat[j][i]);
            for (int i = 0; i < n; i++)
                reverse(mat[i].begin(), mat[i].end());
            if (mat == target)
                return true;
        }
        return false;
    }
};
