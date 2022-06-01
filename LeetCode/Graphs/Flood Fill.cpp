// https://leetcode.com/problems/flood-fill/
// Pixel Connectivity - https://homepages.inf.ed.ac.uk/rbf/HIPR2/connect.htm
// Using 2-D vector - https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/

/*An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same
color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on.
Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2

Output: [[2,2,2],[2,2,2]]

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], newColor < 2^16
0 <= sr < m
0 <= sc < n

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void help(vector<vector<int>> &image, int r, int c, int i, int j, int newColor, int oldColor)
    {
        if (i < 0 || j < 0 || i >= r || j >= c)
        {
            return;
        }

        if (image[i][j] != oldColor)
            return;
        image[i][j] = newColor;

        help(image, r, c, i + 1, j, newColor, oldColor);
        help(image, r, c, i, j + 1, newColor, oldColor);
        help(image, r, c, i - 1, j, newColor, oldColor);
        help(image, r, c, i, j - 1, newColor, oldColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int m = image.size();
        if (m == 0)
            return image;
        int n = image[0].size();
        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        if (image[sr][sc] == newColor)
            return image;
        help(image, m, n, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> image(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> image[i][j];
        }
    }

    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    Solution obj;
    image = obj.floodFill(image, sr, sc, newColor);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}