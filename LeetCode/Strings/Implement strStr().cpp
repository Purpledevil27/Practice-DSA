// https://leetcode.com/problems/implement-strstr/

/*Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

Constraints:

1 <= haystack.length, needle.length <= 10^4
haystack and needle consist of only lowercase English characters.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.length() == 0)
        {
            return 0;
        }
        int h = haystack.length();
        int n = needle.length();
        int ans = -1;
        for (int i = 0; i < h - n + 1; i++)
        {
            string s = haystack.substr(i, n);
            if (s == needle)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    string s, t;
    cin >> s >> t;
    Solution obj;
    cout << obj.strStr(s, t);
    return 0;
}