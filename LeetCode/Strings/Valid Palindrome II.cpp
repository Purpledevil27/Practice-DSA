// https://leetcode.com/problems/valid-palindrome-ii/

/*Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "aba"
Output: true

Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:

Input: s = "abc"
Output: false

Constraints:

1 <= s.length <= 10^5
s consists of lowercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s, int i, int j, int count)
    {
        if (count > 1)
        {
            return false;
        }
        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return isPalindrome(s, i + 1, j, count + 1) || isPalindrome(s, i, j - 1, count + 1);
            }
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        return isPalindrome(s, i, j, 0);
    }
};

int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.validPalindrome(s);
    return 0;
}