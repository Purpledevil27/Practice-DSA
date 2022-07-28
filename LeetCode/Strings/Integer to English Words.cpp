// https://leetcode.com/problems/integer-to-english-words/

/*Convert a non-negative integer num to its English words representation.

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"

Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Constraints:
0 <= num <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";

        vector<string> twoDigit = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

        if (num > 9 && num < 20)
            return twoDigit[num % 10];

        int i = 0, init = 0;

        vector<vector<string>> state = {
            {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"},
            {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"},
            {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"}};

        string ans = "";

        while (num != 0)
        {
            if (num % 10 != 0 && (i == 2 || i == 5 || i == 8))
                ans = " Hundred" + ans;
            if (num % 1000 != 0 && i == 3)
                ans = " Thousand" + ans;
            if (num % 1000 != 0 && i == 6)
                ans = " Million" + ans;
            if (i == 9)
                ans = " Billion" + ans;

            if (i % 3 == 0 && num % 100 > 9 && num % 100 < 20)
            {
                ans = " " + twoDigit[(num % 100) % 10] + ans;
                num /= 100;
                i += 2;
                continue;
            }

            init = num % 10;
            if (init == 0)
            {
                i++;
                num /= 10;
                continue;
            }

            ans = state[i % 3][init] + ans;
            i++;
            num /= 10;
        }

        return ans.substr(1);
    }
};

// Approach #2
class Solution
{
public:
    vector<string> ones = {"zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string english(int n)
    {
        if (n >= 1000000000)
            return english(n / 1000000000) + " Billion" + english(n % 1000000000);
        if (n >= 1000000)
            return english(n / 1000000) + " Million" + english(n % 1000000);
        if (n >= 1000)
            return english(n / 1000) + " Thousand" + english(n % 1000);
        if (n >= 100)
            return english(n / 100) + " Hundred" + english(n % 100);
        if (n >= 20)
            return " " + tens[n / 10 - 2] + english(n % 10);
        if (n >= 1)
            return " " + ones[n];
        return "";
    }

    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        return english(num).substr(1);
    }
};