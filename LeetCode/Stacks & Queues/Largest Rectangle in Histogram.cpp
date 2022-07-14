// https://leetcode.com/problems/largest-rectangle-in-histogram/

/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4

Constraints:
1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // append a zero at the end so that we can pop all elements from the stack and calculate the corresponding areas
        heights.push_back(0);
        int N = heights.size(), ans = 0;
        stack<int> s; // strictly-increasing mono-stack
        for (int i = 0; i < N; ++i)
        {
            while (s.size() && heights[i] <= heights[s.top()]) // Take `heights[i]` as the right edge
            {
                int height = heights[s.top()]; // Take the popped element as the height
                s.pop();
                int left = s.size() ? s.top() : -1; // Take the element left on the stack as the left edge
                ans = max(ans, (i - left - 1) * height);
            }
            s.push(i);
        }
        return ans;
    }
};