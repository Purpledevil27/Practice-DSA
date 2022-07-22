// https://leetcode.com/problems/palindrome-partitioning/

/*Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:

Input: s = "a"
Output: [["a"]]

Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isPalindrome(string const &s)
    {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    vector<vector<string>> ans;
    void solve(string const &s, vector<string> &v, int const &start)
    {
        if (start == s.length())
        {
            ans.push_back(v);
            return;
        }
        for (int i = start; i < s.length(); i++)
        {
            if (isPalindrome(s.substr(start, i - start + 1)))
            {
                v.push_back(s.substr(start, i - start + 1));
                solve(s, v, i + 1);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<string> v;
        solve(s, v, 0);
        return ans;
    }
};

// Similar approach
class Solution
{
    bool isPalindrome(string const &s)
    {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    vector<vector<string>> ans;
    void solve(string s, vector<string> &v)
    {
        if (!s.length())
        {
            ans.push_back(v);
            return;
        }
        for (int i = 1; i <= s.length(); i++)
        {
            if (isPalindrome(s.substr(0, i)))
            {
                v.push_back(s.substr(0, i));
                solve(s.substr(i), v);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<string> v;
        solve(s, v);
        return ans;
    }
};