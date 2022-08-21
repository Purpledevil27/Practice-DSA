// https://leetcode.com/problems/largest-palindromic-number/

/*
You are given a string num consisting of digits only.

Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.

Notes:
You do not need to use all the digits of num, but you must use at least one digit.
The digits can be reordered.

Example 1:

Input: num = "444947137"
Output: "7449447"
Explanation:
Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
It can be shown that "7449447" is the largest palindromic integer that can be formed.

Example 2:

Input: num = "00009"
Output: "9"
Explanation:
It can be shown that "9" is the largest palindromic integer that can be formed.
Note that the integer returned should not contain leading zeroes.

Constraints:
1 <= num.length <= 10^5
num consists of digits.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestPalindromic(string num)
    {
        vector<int> freq(10);
        for (char c : num)
        {
            freq[c - '0']++;
        }

        string left, right;
        for (int j = 9; j >= 0; j--)
        {
            // while (freq[j] > 1 && (j > 0 || left.size()))
            // {
            //     left += '0' + j;
            //     right += '0' + j;
            //     freq[j] -= 2;
            // }

            // Modification for the above while loop
            if (freq[j] > 1 && (j > 0 || left.size()))
            {
                left += string(freq[j] / 2, '0' + j);
                right += string(freq[j] / 2, '0' + j);
                freq[j] = freq[j] % 2;
            }
        }
        for (int i = 9; i >= 0; i--)
        {
            if (freq[i])
            {
                left += '0' + i;
                break;
            }
        }
        reverse(right.begin(), right.end());
        return left + right;
    }
};