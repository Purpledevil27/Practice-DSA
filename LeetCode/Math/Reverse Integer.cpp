// https://leetcode.com/problems/reverse-integer/

/*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

Constraints:
-2^31 <= x <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long long num = x;
        if (num < 0)
            num = -num;
        long long num2 = 0;
        while (num)
        {
            num2 = 10 * num2 + num % 10;
            num /= 10;
            if (num2 >= INT_MAX)
            {
                return 0;
            }
        }
        return x < 0 ? -num2 : num2;
    }
};