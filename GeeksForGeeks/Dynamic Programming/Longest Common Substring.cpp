// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

/*Given two strings. The task is to find the length of the longest common substring.

Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.

Example 2:

Input: S1 = "ABC", S2 "ACB"
Output: 1
Explanation: The longest common substrings are "A", "B", "C" all having length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonSubstr() which takes the string S1, string S2 and their length n and m as inputs and returns the length of the longest common substring in S1 and S2.

Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1<=n, m<=1000
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Bottom Top 1D Dp
class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        vector<int> dp(m + 1, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j > 0; j--)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    dp[j] = 1 + dp[j - 1];
                    ans = max(ans, dp[j]);
                }
                else
                {
                    dp[j] = 0;
                }
            }
        }
        return ans;
    }
};

// Bottom Top 2D Dp
class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends