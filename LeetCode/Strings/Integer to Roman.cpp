// https://leetcode.com/problems/integer-to-roman/

/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.


Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:

1 <= num <= 3999

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ths[] = {"", "M", "MM", "MMM"};

        return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    }
};

class Solution
{
public:
    string intToRoman(int num)
    {
        string snum = to_string(num), ans = "";
        int len = snum.length();
        for (int i = 0; i < len; i++)
        {
            int l = snum.length();
            char stop = snum[0];
            string top = "";
            top += stop;
            int ntop = stoi(top);
            if (l == 1)
            {
                if (ntop < 4)
                {
                    while (ntop != 0)
                    {
                        ans += "I";
                        ntop--;
                    }
                }
                else if (ntop == 4)
                {
                    ans += "IV";
                }
                else if (ntop > 4 && ntop < 9)
                {
                    int t = ntop - 5;
                    ans += "V";
                    while (t != 0)
                    {
                        ans += "I";
                        t--;
                    }
                }
                else if (ntop == 9)
                {
                    ans += "IX";
                }
            }
            if (l == 2)
            {
                if (ntop < 4)
                {
                    while (ntop != 0)
                    {
                        ans += "X";
                        ntop--;
                    }
                }
                else if (ntop == 4)
                {
                    ans += "XL";
                }
                else if (ntop > 4 && ntop < 9)
                {
                    int t = ntop - 5;
                    ans += "L";
                    while (t != 0)
                    {
                        ans += "X";
                        t--;
                    }
                }
                else if (ntop == 9)
                {
                    ans += "XC";
                }
            }
            if (l == 3)
            {
                if (ntop < 4)
                {
                    while (ntop != 0)
                    {
                        ans += "C";
                        ntop--;
                    }
                }
                else if (ntop == 4)
                {
                    ans += "CD";
                }
                else if (ntop > 4 && ntop < 9)
                {
                    int t = ntop - 5;
                    ans += "D";
                    while (t != 0)
                    {
                        ans += "C";
                        t--;
                    }
                }
                else if (ntop == 9)
                {
                    ans += "CM";
                }
            }
            if (l == 4)
            {
                if (ntop < 4)
                {
                    while (ntop != 0)
                    {
                        ans += "M";
                        ntop--;
                    }
                }
            }
            snum = snum.substr(1);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution obj;
    cout << obj.intToRoman(n);
    return 0;
}