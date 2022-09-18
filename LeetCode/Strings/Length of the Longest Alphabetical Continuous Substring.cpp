// https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/

/*An alphabetical continuous string is a string consisting of consecutive letters in the alphabet. In other words, it is any substring of the string "abcdefghijklmnopqrstuvwxyz".

For example, "abc" is an alphabetical continuous string, while "acb" and "za" are not.
Given a string s consisting of lowercase letters only, return the length of the longest alphabetical continuous substring.

Example 1:

Input: s = "abacaba"
Output: 2
Explanation: There are 4 distinct continuous substrings: "a", "b", "c" and "ab".
"ab" is the longest continuous substring.

Example 2:

Input: s = "abcde"
Output: 5
Explanation: "abcde" is the longest continuous substring.

Constraints:
1 <= s.length <= 10^5
s consists of only English lowercase letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int curr = s[0];
        int ans = 1, temp = 1;
        ;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == curr + 1)
            {
                temp++;
                ans = max(temp, ans);
            }
            else
            {
                temp = 1;
            }
            curr = s[i];
        }
        return ans;
    }
};