// https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/

/*You are given a binary string s. In one second, all occurrences of "01" are simultaneously replaced with "10". This process repeats until no occurrences of "01" exist.

Return the number of seconds needed to complete this process.

Example 1:

Input: s = "0110101"
Output: 4
Explanation:
After one second, s becomes "1011010".
After another second, s becomes "1101100".
After the third second, s becomes "1110100".
After the fourth second, s becomes "1111000".
No occurrence of "01" exists any longer, and the process needed 4 seconds to complete,
so we return 4.

Example 2:

Input: s = "11100"
Output: 0
Explanation:
No occurrence of "01" exists in s, and the processes needed 0 seconds to complete,
so we return 0.

Constraints:
1 <= s.length <= 1000
s[i] is either '0' or '1'.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force - Write a DP solution
class Solution
{
public:
    int secondsToRemoveOccurrences(string s)
    {
        int seconds = 0, changed = true;
        while (changed)
        {
            changed = false;
            for (int i = 0; i < s.size() - 1; ++i)
            {
                if (s[i] == '0' && s[i + 1] == '1')
                {
                    swap(s[i], s[i + 1]);
                    ++i;
                    changed = true;
                }
            }
            seconds += changed;
        }
        return seconds;
    }
};