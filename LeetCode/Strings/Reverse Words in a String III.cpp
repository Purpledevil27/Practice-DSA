// https://leetcode.com/problems/reverse-words-in-a-string-iii/

/*Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:

Input: s = "God Ding"
Output: "doG gniD"

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // reverse the whole string
        reverse(s.begin(), s.begin());
        int i = 0, n = s.length();
        while (i < n)
        {
            // find the index of next space
            int space = find(s.begin() + i, s.end(), ' ') - s.begin();
            // reverse the individual word
            reverse(s.begin() + i, s.begin() + space);
            i = space + 1;
        }
        return s;
    }
};

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        int j = 0;

        for (int i = 0; i <= n; i++)
        {
            if (s[i] == ' ' || s[i] == '\0')
            { // s[i]=='\0' for last word//
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            }
        }
        return s;
    }
};