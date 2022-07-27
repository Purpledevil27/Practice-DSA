// https://leetcode.com/problems/reverse-words-in-a-string/

/*Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Constraints:
1 <= s.length <= 10^4
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    string reverseWords(string s)
    {
        string ans = "", v = "";
        bool word = false;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && !word)
            {
                continue;
            }
            else if (s[i] == ' ' && word)
            {
                reverse(v.begin(), v.end());
                ans += v;
                ans += ' ';
                v = "";
                word = false;
            }
            else
            {
                word = true;
                v += s[i];
            }
        }
        reverse(v.begin(), v.end());
        ans += v;
        return ans[ans.size() - 1] == ' ' ? ans.substr(0, ans.size() - 1) : ans;
    }
};

// Approach #2
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        int rev = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else
            {
                int revend = i;
                while (revend < s.size() && s[revend] != ' ')
                {
                    revend++;
                }
                reverse(s.begin() + i, s.begin() + revend);
                i = revend;
            }
        }
        bool space = true;
        rev = 0;
        int last = 0;
        while (rev < s.size())
        {
            if (space && s[rev] == ' ')
            {
                s.erase(rev, 1);
            }
            else if (!space && s[rev] == ' ')
            {
                last = rev;
                space = true;
                rev++;
            }
            else
            {
                space = false;
                rev++;
            }
        }
        if (last != 0 && last + 1 == s.size())
            s = s.substr(0, last);
        return s;
    }
};