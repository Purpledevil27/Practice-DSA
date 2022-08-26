// https://leetcode.com/problems/reordered-power-of-2/

/*You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

Example 1:

Input: n = 1
Output: true

Example 2:

Input: n = 10
Output: false

Constraints:
1 <= n <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string t = to_string(n);
        sort(t.begin(), t.end());

        // Precalculate the power of 2 and sort it. If sorted string matches with the given num return true
        for (int i = 0; i < 30; i++)
        {
            int num = (int)(pow(2, i));
            string s = to_string(num);
            sort(s.begin(), s.end());
            if (s == t)
            {
                return true;
            }
        }
        return false;
    }
};