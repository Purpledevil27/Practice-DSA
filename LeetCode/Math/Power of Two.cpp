// https://leetcode.com/problems/power-of-two/

/*Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2^x.

Example 1:

Input: n = 1
Output: true
Explanation: 2^0 = 1

Example 2:

Input: n = 16
Output: true
Explanation: 2^4 = 16

Example 3:

Input: n = 3
Output: false

Constraints:
-2^31 <= n <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        while (n > 1)
        {
            if (n % 2 != 0)
                return false;
            n /= 2;
        }
        return true;
    }
};

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        long x = 1;
        if (n == 1)
        {
            return 1;
        }
        while (n >= x)
        {
            if (x == n)
            {
                return 1;
            }
            x = x * 2;
        }
        return 0;
    }
};