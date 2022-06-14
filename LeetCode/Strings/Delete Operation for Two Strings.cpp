// https://leetcode.com/problems/delete-operation-for-two-strings/

/*Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming - Tabulation
class Solution
{
public:
    int minDistance(string &word1, string &word2)
    {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1));
        for (int i = 0; i <= word1.length(); i++)
        {
            for (int j = 0; j <= word2.length(); j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = i + j;
                }
                else
                {
                    if (word1[i - 1] == word2[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};

// Dynamic Programming - Memoization
class Solution
{
public:
    vector<vector<int>> dp;
    int solve(string &w1, string &w2, int i, int j)
    {
        if (w1.length() == i && w2.length() == j)
        {
            return 0;
        }

        if (w1.length() == i || w2.length() == j)
        {
            return max(w1.length() - i, w2.length() - j);
        }

        if (dp[i][j] != 1000)
        {
            return dp[i][j];
        }

        if (w1[i] == w2[j])
        {
            return solve(w1, w2, i + 1, j + 1);
        }
        else
            return dp[i][j] = 1 + min(solve(w1, w2, i + 1, j), solve(w1, w2, i, j + 1));
    }
    int minDistance(string &word1, string &word2)
    {
        // vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, INT_MAX));
        dp.resize(word1.length() + 1, vector<int>(word2.length() + 1, 1000));
        return solve(word1, word2, 0, 0);
    }
};

int main()
{
    string w1, w2;
    cin >> w1 >> w2;
    Solution obj;
    cout << obj.minDistance(w1, w2);
    return 0;
}