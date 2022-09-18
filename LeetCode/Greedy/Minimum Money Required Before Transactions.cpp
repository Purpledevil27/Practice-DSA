// https://leetcode.com/problems/minimum-money-required-before-transactions/

/*You are given a 0-indexed 2D integer array transactions, where transactions[i] = [costi, cashbacki].

The array describes transactions, where each transaction must be completed exactly once in some order. At any given moment, you have a certain amount of money. In order to complete transaction i, money >= costi must hold true. After performing a transaction, money becomes money - costi + cashbacki.

Return the minimum amount of money required before any transaction so that all of the transactions can be completed regardless of the order of the transactions.

Example 1:

Input: transactions = [[2,1],[5,0],[4,2]]
Output: 10
Explanation: Starting with money = 10, the transactions can be performed in any order.
It can be shown that starting with money < 10 will fail to complete all transactions in some order.

Example 2:

Input: transactions = [[3,0],[0,3]]
Output: 3
Explanation:
- If transactions are in the order [[3,0],[0,3]], the minimum money required to complete the transactions is 3.
- If transactions are in the order [[0,3],[3,0]], the minimum money required to complete the transactions is 0.
Thus, starting with money = 3, the transactions can be performed in any order.

Constraints:
1 <= transactions.length <= 10^5
transactions[i].length == 2
0 <= costi, cashbacki <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

/*We need to compute how much money we must spend, which is sum(cost_i - cachback_i).

Note that we do not care about the profit - as we can execute those transactions at the very end. We just assume that we need to spend zero on those transactions.

There is also an overhead on top of what we need to spend. We have two cases here:

For negative transactions, the cashback from the very last transaction cannot be utilized, so we need to add it to spend.
We track the maximum cashback for those transactions.
For neutral transactions, we need an upfront cost to make the first transaction.
We track the maximum cost for such transactions.
In the end, we need at least spend + max(cachback, cost) money to execute all transactions in any order.
*/

#define ll long long
class Solution
{
public:
    long long minimumMoney(vector<vector<int>> &t)
    {
        ll ans = 0;
        for (auto &i : t)
        {
            // Since we are going to ignore the cashback for ONE transaction which will come at the last.
            // ans = max(ans, (ll)min(i[0], i[1]));
            if (i[0] - i[1] > 0)
            {
                ans = max(ans, (ll)i[1]);
            }
            else
            {
                ans = max(ans, (ll)i[0]);
            }
        }
        // adding all the negative delta transaction
        for (auto &i : t)
        {
            ans = ans + (i[0] - i[1] > 0 ? (i[0] - i[1]) : 0);
        }
        return ans;
    }
};