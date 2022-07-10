// https://leetcode.com/problems/min-cost-climbing-stairs/

/*You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/

#include <bits/stdc++.h>
using namespace std;

// Using Dp
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int dp1 = cost[0];
        int dp2 = cost[1];
        for (int i = 2; i < n; i++)
        {
            int t = cost[i] + min(dp1, dp2);
            dp1 = dp2;
            dp2 = t;
        }
        return min(dp1, dp2);
    }
};

// Using memoization
class Solution
{
public:
    int dp[1001];
    int solve(vector<int> &cost, int n)
    {
        if (n <= 1)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans = 0;
        int step1 = solve(cost, n - 1) + cost[n - 1];
        int step2 = solve(cost, n - 2) + cost[n - 2];
        return dp[n] = ans + min(step1, step2);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(cost, n);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> cost;
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    Solution obj;
    cout << obj.minCostClimbingStairs(cost);
    return 0;
}