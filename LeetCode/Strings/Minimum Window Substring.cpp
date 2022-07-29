// https://leetcode.com/problems/minimum-window-substring/

/*Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:
m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int d = INT_MAX, counter = t.size(), start = 0, end = 0, head = 0;
        vector<int> map(128, 0);
        for (auto c : t)
            map[c]++;

        while (end < s.size())
        {
            if (map[s[end]] > 0)
                counter--;
            map[s[end]]--;
            end++;
            while (counter == 0)
            {
                if (end - start < d)
                {
                    d = end - start;
                    head = start;
                }
                map[s[start]]++;
                if (map[s[start]] > 0)
                    counter++;

                start++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};