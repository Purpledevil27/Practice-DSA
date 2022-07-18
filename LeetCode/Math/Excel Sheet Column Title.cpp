// https://leetcode.com/problems/excel-sheet-column-title/

/*Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

Example 1:
Input: columnNumber = 1
Output: "A"

Example 2:
Input: columnNumber = 28
Output: "AB"

Example 3:
Input: columnNumber = 701
Output: "ZY"

Constraints:
1 <= columnNumber <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans = "";

        while (columnNumber > 0)
        {
            int curr = (--columnNumber) % 26;
            ans = char('A' + curr) + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};

// Approach #2
class Solution
{
public:
    string convertToTitle(int n)
    {
        return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char)((n - 1) % 26 + 'A');
    }
};
