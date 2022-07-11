// https://leetcode.com/problems/maximum-number-of-visible-points/

/*You are given an array points, an integer angle, and your location, where location = [posx, posy] and points[i] = [xi, yi] both denote integral coordinates on the X-Y plane.

Initially, you are facing directly east from your position. You cannot move from your position, but you can rotate. In other words,
posx and posy cannot be changed. Your field of view in degrees is represented by angle, determining how wide you can see from any
given view direction. Let d be the amount in degrees that you rotate counterclockwise. Then, your field of view is the inclusive range of angles [d - angle/2, d + angle/2].

You can see some set of points if, for each point, the angle formed by the point, your position, and the immediate east direction from your position is in your field of view.

There can be multiple points at one coordinate. There may be points at your location, and you can always see these points regardless of your rotation. Points do not obstruct your vision to other points.

Return the maximum number of points you can see.

Example 1:


Input: points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
Output: 3
Explanation: The shaded region represents your field of view. All points can be made visible in your field of view, including [3,3] even though [2,2] is in front and in the same line of sight.
Example 2:

Input: points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
Output: 4
Explanation: All points can be made visible in your field of view, including the one at your location.
Example 3:

Input: points = [[1,0],[2,1]], angle = 13, location = [1,1]
Output: 1
Explanation: You can only see one of the two points, as shown above.

Constraints:

1 <= points.length <= 10^5
points[i].length == 2
location.length == 2
0 <= angle < 360
0 <= posx, posy, xi, yi <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location)
    {
        vector<double> angles;
        int ans = 0, overlap = 0;
        for (auto point : points)
        {
            if (point[0] == location[0] && point[1] == location[1])
            {
                // counting the point overlapping the current location
                overlap++;
            }
            else
            {
                // pushing angles made between point and my location in degrees
                angles.push_back(atan2(point[1] - location[1], point[0] - location[0]) * 180 / M_PI);
            }
        }
        sort(angles.begin(), angles.end());
        int size = angles.size();

        // Making the loop run twice to handle the counterclockwise rotation (Test case - [[0,0],[0,2]]/n 90/n [1,1])
        for (int i = 0, j = 0; i < size * 2; i++)
        {
            if (360 * (i >= size) + angles[i % size] - 360 * (j >= size) - angles[j % size] > angle)
            {
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans + overlap;
    }
};
