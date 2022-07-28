// https://leetcode.com/problems/valid-number/

/*A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.

A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
One or more digits, followed by a dot '.'.
One or more digits, followed by a dot '.', followed by one or more digits.
A dot '.', followed by one or more digits.

An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One or more digits.
For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"],
while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.

Example 1:

Input: s = "0"
Output: true

Example 2:

Input: s = "e"
Output: false

Example 3:

Input: s = "."
Output: false

Constraints:
1 <= s.length <= 20
s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
*/

/*
STATES
//#0  #1  #2   #3   #4   #5
init sign digit dot e invalid
0    1     2    3   9    9     #0 - init
9    9     2    3   9    9     #1 - sign
8    9     2    4   5    9     #2 - digit
9    9     4    9   9    9     #3 - dot
8    9     4    9   5    9     #4 - number
9    6     7    9   9    9     #5 - e
9    9     7    9   9    9     #6 - e_sign
8    9     7    9   9    9     #7 - e_digit
8    9     9    9   9    9     #8 - success
9    9     9    9   9    9     #9 - fail
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1 - DFA - Deterministic finite automaton
class Solution
{
    int getInput(char const &c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' || c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        if (c == '.')
            return 3;
        if (c == 'e' || c == 'E')
            return 4;
        return 5;
    }

public:
    bool isNumber(string s)
    {
        vector<vector<int>> state = {
            {0, 1, 2, 3, 9, 9},
            {9, 9, 2, 3, 9, 9},
            {8, 9, 2, 4, 5, 9},
            {9, 9, 4, 9, 9, 9},
            {8, 9, 4, 9, 5, 9},
            {9, 6, 7, 9, 9, 9},
            {9, 9, 7, 9, 9, 9},
            {8, 9, 7, 9, 9, 9},
            {8, 9, 9, 9, 9, 9},
            {9, 9, 9, 9, 9, 9},
        };
        int finalState = 0;
        for (auto &c : s)
        {
            finalState = state[finalState][getInput(c)];
            if (finalState == 9)
                return false;
        }
        finalState = state[finalState][0];
        return finalState == 8;
    }
};

// Approach #2
class Solution
{
public:
    bool isNumber(string s)
    {
        int n = s.size(), i = 0, digits = 0, dots = 0;
        for (; i < n && isspace(s[i]); i++)
            ;
        if (s[i] == '+' || s[i] == '-')
        {
            i++;
        }
        for (; i < n && (isdigit(s[i]) || s[i] == '.'); i++)
        {
            isdigit(s[i]) ? digits++ : dots++;
        }
        if (!digits || dots > 1)
        {
            return false;
        }
        if (s[i] == 'e' || s[i] == 'E')
        {
            i++;
            if (s[i] == '+' || s[i] == '-')
            {
                i++;
            }
            digits = 0;
            for (; i < n && isdigit(s[i]); i++)
            {
                digits++;
            }
            if (!digits)
            {
                return false;
            }
        }
        for (; i < n && isspace(s[i]); i++)
            ;
        return i == n;
    }
};