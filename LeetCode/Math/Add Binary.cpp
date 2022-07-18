// https://leetcode.com/problems/add-binary/

/*Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
1 <= a.length, b.length <= 10^4
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1, j = b.size() - 1;
        int sum = 0;
        while (i >= 0 && j >= 0)
        {
            sum += (a[i] - '0') + (b[j] - '0');
            a[i] = char(sum % 2 + '0');
            sum /= 2;
            i--, j--;
        }
        while (i >= 0)
        {
            sum += (a[i] - '0');
            a[i] = char(sum % 2 + '0');
            sum /= 2;
            i--;
        }

        while (j >= 0)
        {
            sum += (b[j] - '0');
            a = string(1, char(sum % 2 + '0')) + a;
            sum /= 2;
            j--;
        }
        if (sum)
            a = string(1, char(sum + '0')) + a;
        return a;
    }
};

// Approach #2
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int n = max(a.length(), b.length()) - 1;
        if (a.length() > b.length())
        {
            while (a.length() != b.length())
            {
                b = "0" + b;
            }
        }
        else
        {
            while (a.length() != b.length())
            {
                a = "0" + a;
            }
        }
        string ans = "";
        int rem = 0;
        for (int i = n; i >= 0; i--)
        {
            if (a[i] == '0' && b[i] == '0')
            {
                if (rem != 0)
                {
                    ans = "1" + ans;
                    rem = 0;
                }
                else
                {
                    ans = "0" + ans;
                }
            }
            else if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
            {
                if (rem == 0)
                {
                    ans = "1" + ans;
                    rem = 0;
                }
                else
                {
                    ans = "0" + ans;
                    rem = 1;
                }
            }
            else
            {
                if (rem == 0)
                    ans = "0" + ans;
                else
                    ans = "1" + ans;
                rem = 1;
            }
        }
        if (rem)
            ans = "1" + ans;
        return ans;
    }
};
