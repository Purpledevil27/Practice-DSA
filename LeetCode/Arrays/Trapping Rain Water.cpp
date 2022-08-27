// https://leetcode.com/problems/trapping-rain-water/

/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:
n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Using Monotonic stack
class Solution
{
public:
    int trap(vector<int> &height)
    {
        stack<int> s; // strictly decreasing stack
        int max_water = 0;
        int i = 0;
        while (i < height.size())
        {
            if (s.empty() || height[i] <= height[s.top()])
            {
                s.push(i++);
            }
            else
            {
                int bar = height[s.top()];
                s.pop();
                cout << bar << height[i];
                cout << endl;
                max_water += s.empty() ? 0 : ((min(height[i], height[s.top()]) - bar) * (i - s.top() - 1));
            }
        }
        return max_water;
    }
};

// Finding the left max height and right max height
class Solution
{
public:
    int trap(vector<int> &bar)
    {
        int n = bar.size();
        if (n <= 2)
            return 0;
        int ans = 0;
        // left[i] is the max height on the left side of i
        vector<int> left(n - 1);
        left[0] = INT_MIN;

        for (int i = 1; i < n - 1; i++)
        {
            left[i] = max(left[i - 1], bar[i - 1]);
        }

        // it is the max height on the right side
        int right = INT_MIN;

        for (int i = n - 2; i >= 1; i--)
        {
            right = max(bar[i + 1], right);

            if (min(left[i], right) > bar[i])
            {
                ans += (min(left[i], right) - bar[i]);
            }
        }
        return ans;
    }
};

// Using binary search method
class Solution
{
public:
    int trap(vector<int> &height)
    {

        int n = height.size();
        int left = 0;
        int right = n - 1;
        int res = 0;
        int maxleft = 0, maxright = 0;

        while (left <= right)
        {

            if (height[left] <= height[right])
            {

                if (height[left] >= maxleft)
                    maxleft = height[left];
                else
                    res += maxleft - height[left];

                left++;
            }
            else
            {

                if (height[right] >= maxright)
                    maxright = height[right];
                else
                    res += maxright - height[right];

                right--;
            }
        }
        return res;
    }
};