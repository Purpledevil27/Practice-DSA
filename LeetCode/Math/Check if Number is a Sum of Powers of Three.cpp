// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

/*Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.

Example 1:

Input: n = 12
Output: true
Explanation: 12 = 31 + 32

Example 2:

Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34

Example 3:

Input: n = 21
Output: false

Constraints:
1 <= n <= 10^7
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        if (n == 1)
            return true;
        if (n % 3 == 2)
            return false;
        return checkPowersOfThree(n / 3);
    }
};

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        int r = 0;
        while (n > 2 && r != 2)
        {
            r = n % 3;
            n /= 3;
        }
        return r != 2;
    }
};