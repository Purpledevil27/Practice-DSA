// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

Constraints:
0 <= k <= 100
0 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(), count = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                count += prices[i] - prices[i - 1];
            }
        }
        return count;
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // k is greater than half of size of prices that means we can make as many transactions as we like
        if (k > n / 2)
        {
            return maxProfit(prices);
        }

        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for (int i = 1; i <= k; i++)
        {
            int maxdiff = dp[i - 1][0] - prices[0];
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxdiff);
                maxdiff = max(maxdiff, dp[i - 1][j] - prices[j]);
            }
        }
        return dp[k][n - 1];
    }
};