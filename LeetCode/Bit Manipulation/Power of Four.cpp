// https://leetcode.com/problems/power-of-four/

/*Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:

Input: n = 16
Output: true

Example 2:

Input: n = 5
Output: false

Example 3:

Input: n = 1
Output: true

Constraints:
-2^31 <= n <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1 - Using Bit manipulation
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;
        while (n > 1)
        {
            if (n & 1 != 0)
            {
                return false;
            }
            n >>= 1;
            if (n & 1 != 0)
            {
                return false;
            }
            n >>= 1;
        }
        return true;
    }
};

// Approach #2 - Using Recursion
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;

        return n % 4 == 0 && isPowerOfFour(n / 4);
    }
};