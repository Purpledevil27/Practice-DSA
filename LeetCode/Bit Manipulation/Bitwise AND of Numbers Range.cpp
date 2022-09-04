// https://leetcode.com/problems/bitwise-and-of-numbers-range/

/*Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

Example 1:
Input: left = 5, right = 7
Output: 4

Example 2:
Input: left = 0, right = 0
Output: 0

Example 3:
Input: left = 1, right = 2147483647
Output: 0

Constraints:
0 <= left <= right <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        // if we do bitwise AND for every number it will give TLE. Bitwise AND has property that it always result a smaller value.
        while (right > left)
        {
            right = right & (right - 1);
        }
        return left & right;
    }
};