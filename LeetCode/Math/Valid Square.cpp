// https://leetcode.com/problems/valid-square/

/*Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).

Example 1:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true

Example 2:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
Output: false

Example 3:

Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
Output: true

Constraints:
p1.length == p2.length == p3.length == p4.length == 2
-10^4 <= xi, yi <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dis(vector<int> const &s, vector<int> const &n)
    {
        return (n[0] - s[0]) * (n[0] - s[0]) + (n[1] - s[1]) * (n[1] - s[1]);
    }

public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        unordered_map<int, int> m;
        m[dis(p1, p2)]++;
        m[dis(p1, p3)]++;
        m[dis(p1, p4)]++;
        m[dis(p2, p3)]++;
        m[dis(p2, p4)]++;
        m[dis(p3, p4)]++;
        return !m.count(0) && m.size() == 2;
    }
};