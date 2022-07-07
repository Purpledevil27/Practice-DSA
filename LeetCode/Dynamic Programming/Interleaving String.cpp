// https://leetcode.com/problems/interleaving-string/

/*Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

// Using 1D Dp
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        vector<int> dp(n2 + 1);
        for (int i = 0; i <= n1; i++)
        {
            for (int j = 0; j <= n2; j++)
            {
                if (j == 0 && i == 0)
                {
                    dp[j] = 1;
                }
                else if (i == 0)
                {
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                }
                else if (j == 0)
                {
                    dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
                }
                else
                {
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                            (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[n2];
    }
};

// Using 2D Dp
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        for (int i = 0; i <= n1; i++)
        {
            for (int j = 0; j <= n2; j++)
            {
                if (j == 0 && i == 0)
                {
                    dp[i][j] = 1;
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                               (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};

// Using Memoization
class Solution
{
public:
    int dp[101][101];
    bool solve(string s1, string s2, string s3)
    {
        if (s3.length() == 0)
        {
            return true;
        }
        if (s1[0] != s3[0] && s2[0] != s3[0])
        {
            return false;
        }
        if (dp[s1.length()][s2.length()] != -1)
        {
            return dp[s1.length()][s2.length()];
        }
        if (s1[0] == s3[0] && s3[0] == s2[0])
        {
            return dp[s1.length()][s2.length()] = solve(s1.substr(1), s2, s3.substr(1)) || solve(s1, s2.substr(1), s3.substr(1));
        }
        if (s1[0] == s3[0])
        {
            return dp[s1.length()][s2.length()] = solve(s1.substr(1), s2, s3.substr(1));
        }
        if (s2[0] == s3[0])
        {
            return dp[s1.length()][s2.length()] = solve(s1, s2.substr(1), s3.substr(1));
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        memset(dp, -1, sizeof(dp));
        if (n1 + n2 != n3)
        {
            return false;
        }
        return solve(s1, s2, s3);
    }
};

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    Solution obj;
    cout << obj.isInterleave(s1, s2, s3);
    return 0;
}