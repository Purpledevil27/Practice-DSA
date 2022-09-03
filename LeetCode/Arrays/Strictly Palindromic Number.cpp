// https://leetcode.com/problems/strictly-palindromic-number/

/*An integer n is strictly palindromic if, for every base b between 2 and n - 2 (inclusive), the string representation of the integer n in base b is palindromic.

Given an integer n, return true if n is strictly palindromic and false otherwise.

A string is palindromic if it reads the same forward and backward.

Example 1:

Input: n = 9
Output: false
Explanation: In base 2: 9 = 1001 (base 2), which is palindromic.
In base 3: 9 = 100 (base 3), which is not palindromic.
Therefore, 9 is not strictly palindromic so we return false.
Note that in bases 4, 5, 6, and 7, n = 9 is also not palindromic.

Example 2:

Input: n = 4
Output: false
Explanation: We only consider base 2: 4 = 100 (base 2), which is not palindromic.
Therefore, we return false.

Constraints:
4 <= n <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Apporach #1
class Solution
{
public:
    bool isStrictlyPalindrome(int n)
    {
        // The condition is extreme hard to satisfy, think about it...
        // for every base b between 2 and n - 2...
        // 4 is not strictly palindromic number
        // 5 is not strictly palindromic number
        // ..
        // then the bigger, the more impossible.
        // Just return false
        return false;
    }
};

// Approach #2
class Solution
{
public:
    bool isPalindrome(string const &S)
    {
        // Stores the reverse of the
        // string S
        string P = S;

        // Reverse the string P
        reverse(P.begin(), P.end());

        if (S == P)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    char reVal(int const &num)
    {
        if (num >= 0 && num <= 9)
            return (char)(num + '0');
        else
            return (char)(num - 10 + 'A');
    }

    // Function to convert a given decimal number
    // to a base 'base' and
    string fromDeci(string &res, int const &base, int inputNum)
    {
        int index = 0; // Initialize index of result

        // Convert input number is given base by repeatedly
        // dividing it by base and taking remainder
        while (inputNum > 0)
        {
            res.push_back(reVal(inputNum % base));
            index++;
            inputNum /= base;
        }

        // Reverse the result
        reverse(res.begin(), res.end());

        return res;
    }
    bool isStrictlyPalindromic(int n)
    {
        string res;
        for (int i = 2; i <= n - 2; i++)
        {
            string ans = fromDeci(res, i, n);
            if (!isPalindrome(ans))
            {
                return false;
            }
        }
        return true;
    }
};