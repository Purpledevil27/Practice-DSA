// https://leetcode.com/problems/non-overlapping-intervals/

/*Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

Constraints:

1 <= intervals.length <= 10^5
intervals[i].length == 2
-5 * 10^4 <= starti < endi <= 5 * 10^4

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> const &s, vector<int> const &n)
             { return s[0] < n[0]; });
        int lastIntervalEnd = intervals[0][1], ans = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            // As it is sorted, we will only take interval with ending having smaller value
            if (intervals[i][0] < lastIntervalEnd)
            {
                ans++;
                // Updating last interval ending if current interval ending is a smaller value than lastIntervalEnd
                if (intervals[i][1] < lastIntervalEnd)
                {
                    lastIntervalEnd = intervals[i][1];
                }
            }
            else
            {
                lastIntervalEnd = intervals[i][1];
            }
        }
        return ans;
    }
};