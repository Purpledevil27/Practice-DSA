// https://leetcode.com/problems/the-skyline-problem/

/*A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...].
Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends.
Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]

Example 1:

Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.

Example 2:

Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]

Constraints:

1 <= buildings.length <= 10^4
0 <= lefti < righti <= 2^31 - 1
1 <= heighti <= 231 - 1
buildings is sorted by lefti in non-decreasing order.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1 - using priority queue
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        // pq<{height, right}>, pops taller first
        priority_queue<pair<int, int>> pq;

        vector<int> boundaries; // x points
        for (auto &building : buildings)
        {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());

        vector<vector<int>> ans;
        int n = buildings.size(), idx = 0;
        for (auto &boundary : boundaries)
        {
            // left <= current boundary, then push right & height into pq
            while (idx < n && buildings[idx][0] <= boundary)
            {
                pq.emplace(buildings[idx][2], buildings[idx][1]);
                idx++;
            }

            // pop all right <= boundary
            while (!pq.empty() && pq.top().second <= boundary)
            {
                pq.pop();
            }

            int maxn = pq.empty() ? 0 : pq.top().first;
            if (ans.size() == 0 || maxn != ans.back()[1])
            {
                ans.push_back({boundary, maxn});
            }
        }
        return ans;
    }
};

// Approach #2 - using multimap and multiset

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        multimap<int, int> coords;
        for (const vector<int> &building : buildings)
        {
            coords.emplace(building[0], building[2]);
            coords.emplace(building[1], -building[2]);
        }

        multiset<int> heights = {0};
        vector<vector<int>> corners;
        int x = -1;
        int y = 0;
        for (const pair<int, int> &p : coords)
        {
            if ((x >= 0) && (p.first != x) && (corners.empty() || ((*corners.rbegin())[1] != y)))
            {
                corners.push_back({x, y});
            }

            if (p.second >= 0)
            {
                heights.insert(p.second);
            }
            else
            {
                heights.erase(heights.find(-p.second));
            }

            x = p.first;
            y = *heights.rbegin();
        }

        if (!corners.empty())
        {
            corners.push_back({x, 0});
        }
        return corners;
    }
};
