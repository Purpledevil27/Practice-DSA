// https://leetcode.com/problems/power-of-three/

/*Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:

Input: n = 27
Output: true

Example 2:

Input: n = 0
Output: false

Example 3:

Input: n = 9
Output: true

Constraints:
-2^31 <= n <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        return (n % 3 == 0) && (isPowerOfThree(n / 3));
    }
};

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;
        int x = (ceil)(log(n) / log(3));
        cout << x << endl;
        if (pow(3, x) == n)
        {
            return true;
        }
        return false;
    }
};

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // n must be greater than 0 and the largest power of 3 is 3^19 and since 3 is prime, only a power of 3 would be divisible
        return n > 0 && 1162261467 % n == 0;
    }
};