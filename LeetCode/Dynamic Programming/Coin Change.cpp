// https://leetcode.com/problems/coin-change/
/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any
combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4

*/

#include <bits/stdc++.h>
using namespace std;

// Using Dynamic Programming
class Solution
{
    int count(vector<int> &coins, int size, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        vector<int> table(amount + 1, INT_MAX);
        table[0] = 0;
        for (int i = 0; i <= amount; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (coins[j] <= i)
                {
                    int subans = table[i - coins[j]];
                    if (subans != INT_MAX && subans + 1 < table[i])
                    {
                        table[i] = subans + 1;
                    }
                }
            }
        }
        if (table[amount] == INT_MAX)
        {
            return -1;
        }
        return table[amount];
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        return count(coins, coins.size(), amount);
    }
};

// Brute Force
class Solution
{
    int count(vector<int> &coins, int size, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = 0; i < size; i++)
        {
            if (coins[i] <= amount)
            {
                int subans = count(coins, size, amount - coins[i]);

                if (subans != INT_MAX && subans + 1 < ans)
                {
                    ans = subans + 1;
                }
            }
        }
        return ans;
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        return count(coins, coins.size(), amount);
    }
};

// Using Brute force and by method of total no. of ways to get to amount X
class Solution
{
    int ans = INT_MAX;
    void count(vector<int> &coins, int size, int amount, int c)
    {
        if (amount == 0)
        {
            ans = min(ans, c);
            return;
        }
        if (amount < 0)
            return;

        if (size <= 0 && amount >= 1)
            return;

        count(coins, size - 1, amount, c);
        count(coins, size, amount - coins[size - 1], c + 1);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        count(coins, coins.size(), amount, 0);
        if (ans != INT_MAX)
            return ans;
        return -1;
    }
};

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        v.push_back(k);
    }

    Solution obj;
    cout << obj.coinChange(v, x);

    return 0;
}