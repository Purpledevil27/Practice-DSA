// https://leetcode.com/problems/binary-number-with-alternating-bits/

/*Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:

Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101

Example 2:

Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.

Example 3:

Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.

Constraints:
1 <= n <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        bool one = false;
        one = (n & 1) == 0 ? false : true;
        n >>= 1;
        while (n)
        {
            if ((one && (n & 1)) || (!one && !(n & 1)))
            {
                return false;
            }
            one = !one;
            n >>= 1;
        }
        return true;
    }
};

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int org = __builtin_popcount(n);
        int t;
        if ((n & 1) == 0)
        {
            t = n >> 1;
        }
        else
        {
            t = n << 1;
        }
        t = (t ^ n);
        int fin = __builtin_popcount(t);
        return ((org * 2) == fin && (t & 1) != 0);
    }
};