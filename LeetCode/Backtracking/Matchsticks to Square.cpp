// https://leetcode.com/problems/matchsticks-to-square/

/*You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

Example 1:

Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.

Constraints:

1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Sides of the square
    int side1, side2, side3, side4;
    bool solve(vector<int> &matchsticks, int index)
    {
        if (index == matchsticks.size())
        {
            // if sides are equal return true
            if (side1 == side2 && side2 == side3 && side3 == side4)
                return true;
            return false;
        }
        // there is no point if matchstick length is greater than remaining length of sides since remaining length will get negative
        if (matchsticks[index] <= side1)
        {
            side1 -= matchsticks[index];
            if (solve(matchsticks, index + 1))
            {
                return true;
            }
            // Backtrack
            side1 += matchsticks[index];
        }
        if (matchsticks[index] <= side2)
        {
            side2 -= matchsticks[index];
            if (solve(matchsticks, index + 1))
            {
                return true;
            }
            // Backtrack
            side2 += matchsticks[index];
        }
        if (matchsticks[index] <= side3)
        {
            side3 -= matchsticks[index];
            if (solve(matchsticks, index + 1))
            {
                return true;
            }
            // Backtrack
            side3 += matchsticks[index];
        }
        if (matchsticks[index] <= side4)
        {
            side4 -= matchsticks[index];
            if (solve(matchsticks, index + 1))
            {
                return true;
            }
            // Backtrack
            side4 += matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int> &matchsticks)
    {
        int n = matchsticks.size();
        if (n < 4)
        {
            return false;
        }
        // sorting the array in reverse order to escape cases
        sort(matchsticks.rbegin(), matchsticks.rend());

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        // pruning
        if (sum == 0 || double(sum % 4) != 0)
        {
            return false;
        }
        int side = sum / 4;
        side1 = side, side2 = side, side3 = side, side4 = side;
        return solve(matchsticks, 0);
    }
};