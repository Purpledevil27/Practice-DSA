// https://leetcode.com/problems/first-unique-character-in-a-string/

/*Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0

Example 2:

Input: s = "loveleetcode"
Output: 2

Example 3:

Input: s = "aabb"
Output: -1

Constraints:
1 <= s.length <= 10^5
s consists of only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int freq[26] = {};
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++)
        {
            if (freq[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
