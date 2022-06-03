// https://leetcode.com/problems/decode-string/

/*Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers,
k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 10^5.

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"


Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/

#include <bits/stdc++.h>
using namespace std;

// Using recursion
class Solution
{
public:
    string decode(const string &s, int &i)
    {
        string substr = "";

        while (i < s.length() && s[i] != ']')
        {
            if (!isdigit(s[i]))
            {
                substr += s[i++];
            }
            else
            {
                int n = 0;
                string strnum = "";
                while (isdigit(s[i]) && i < s.length())
                {
                    strnum += s[i++];
                }
                n = stoi(strnum);

                i++;
                string ans = decode(s, i);
                i++;

                while (n--)
                {
                    substr += ans;
                }
            }
        }
        return substr;
    }
    string decodeString(string s)
    {
        int i = 0;
        return decode(s, i);
    }
};

// Using Stacks
class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> intStack;
        stack<string> stringStack;
        string ans = "";
        int num = 0;
        string strnum = "";
        for (auto c : s)
        {
            if (isdigit(c))
            {
                strnum += c;
            }
            else if (c == '[')
            {
                num = stoi(strnum);
                intStack.push(num);
                stringStack.push(ans);

                ans = "";
                strnum = "";
            }
            else if (c == ']')
            {
                int n = intStack.top();
                intStack.pop();
                string t = stringStack.top();
                stringStack.pop();

                while (n--)
                {
                    t = t + ans;
                }
                ans = t;
            }
            else
            {
                ans += c;
            }
        }
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.decodeString(s);
    return 0;
}