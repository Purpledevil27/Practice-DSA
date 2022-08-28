// https://leetcode.com/problems/removing-stars-from-a-string/

/*
You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.

Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".

Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.

Constraints:
1 <= s.length <= 10^5
s consists of lowercase English letters and stars *.
The operation above can be performed on s.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1 using stack
class Solution
{
public:
    string removeStars(string s)
    {
        // we can just use string to simulate the operation
        string ans;
        // iterate each character
        for (auto &c : s)
        {
            // if it is *, then remove the last character
            if (c == '*')
                ans.pop_back();
            // otherwise add it to ans
            else
                ans.push_back(c);
        }
        return ans;
    }
};

// Approach #2 - Traversing and changing the char
class Solution
{
public:
    string removeStars(string s)
    {
        int n = s.length();
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (count != 0 && s[i] != '*')
            {
                s[i] = '*';
                count--;
                continue;
            }
            if (s[i] == '*')
            {
                count++;
            }
        }
        string t = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '*')
            {
                continue;
            }
            t += s[i];
        }
        return t;
    }
};