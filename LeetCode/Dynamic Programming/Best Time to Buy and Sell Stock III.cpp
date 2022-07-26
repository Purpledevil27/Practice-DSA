// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

Constraints:
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1 Time Complexity - O(N)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int oneBuy = INT_MAX, oneSell = 0, twoBuy = INT_MAX, twoSell = 0, n = prices.size();
        for (int i = 0; i < n; i++)
        {
            oneBuy = min(oneBuy, prices[i]);
            oneSell = max(oneSell, prices[i] - oneBuy);
            twoBuy = min(twoBuy, prices[i] - oneSell);
            twoSell = max(twoSell, prices[i] - twoBuy);
        }
        return twoSell;
    }
};

// Approach #2 Time Complexity - O(k*N)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(n, 0));
        for (int k = 1; k <= 2; k++)
        {
            int maxdiff = dp[k - 1][0] - prices[0];
            for (int i = 1; i < n; i++)
            {
                dp[k][i] = max(dp[k][i - 1], prices[i] + maxdiff);
                maxdiff = max(maxdiff, dp[k - 1][i] - prices[i]);
            }
        }
        return dp[2][n - 1];
    }
};

// Approach #3 Time Complexity - O(k*N*N)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(n, 0));
        for (int k = 1; k <= 2; k++)
        {
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    dp[k][i] = max({dp[k][i], dp[k][i - 1], prices[i] - prices[j] + dp[k - 1][j]});
                }
            }
        }
        return dp[2][n - 1];
    }
};