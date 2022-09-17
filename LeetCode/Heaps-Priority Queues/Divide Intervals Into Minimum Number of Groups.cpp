// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

/*You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].

You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.

Return the minimum number of groups you need to make.

Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.



Example 1:

Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.
Example 2:

Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one group.

Constraints:
1 <= intervals.length <= 10^5
intervals[i].length == 2
1 <= lefti <= righti <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1 - using min heap
class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        int n = intervals.size(), ans = 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &i : intervals)
        {
            if (!pq.empty() && pq.top() < i[0])
            {
                pq.pop();
            }
            pq.push(i[1]);
        }
        return pq.size();
    }
};

// Approach #2 same as meeting rooms
// Explanation
// At time point intervals[i][0],
// start using a meeting room(group).

// At time point intervals[i][1] + 1,
// end using a meeting room.

// Sort all events by time,
// and accumulate the number of room(group) used.
class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        map<int, int> m;
        for (auto &v : intervals)
            m[v[0]]++, m[v[1] + 1]--;
        int ans = 0, cur = 0;
        for (auto &v : m)
            ans = max(ans, cur += v.second);
        return ans;
    }
};