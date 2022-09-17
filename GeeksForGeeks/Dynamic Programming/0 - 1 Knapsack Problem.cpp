// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?page=3&sortBy=submissions

/*You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Example 1:

Input: N = 3 W = 4 values[] = {1,2,3} weight[] = {4,5,1}
Output: 3

Example 2:

Input: N = 3 W = 3 values[] = {1,2,3} weight[] = {4,5,6}
Output: 0
Your Task:
Complete the function knapSack() which takes maximum capacity W, weight array wt[], value array val[], and the number of items n as a parameter and returns the maximum possible value you can get.

Expected Time Complexity: O(N*W).
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<vector<int>> dp;
    int solve(int W, int wt[], int val[], int n, int i)
    {
        if (i >= n)
            return 0;
        if (dp[W][i] != -1)
            return dp[W][i];
        int value = 0;
        if (W >= wt[i])
            value = val[i] + solve(W - wt[i], wt, val, n, i + 1);
        return dp[W][i] = max(value, solve(W, wt, val, n, i + 1));
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        dp.resize(W + 1, vector<int>(n + 1, -1));
        return solve(W, wt, val, n, 0);
    }
};

//{ Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}
// } Driver Code Ends