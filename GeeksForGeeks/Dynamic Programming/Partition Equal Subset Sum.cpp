// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

/*Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4 arr = {1, 5, 11, 5}
Output: YES
Explanation: The two parts are {1, 5, 5} and {11}.

Example 2:

Input: N = 3 arr = {1, 3, 5}
Output: NO
Explanation: This array can never be partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.

Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)

Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// Using Dp - Bottom Up
class Solution
{
    bool helper(int arr[], int sum, int n)
    {
        int dp[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];

                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }

public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum % 2 != 0)
            return 0;
        else
            return helper(arr, sum / 2, N);
    }
};

// Using Memoization - Top down
class Solution
{
    bool helper(vector<int> const &v, const int &n, int leftsum, int rightsum, int index, vector<vector<int>> &dp)
    {
        if (index == n)
        {
            return (leftsum == rightsum && leftsum != 0);
        }
        else
        {
            if (dp[index][leftsum] != -1)
                return dp[index][leftsum];
            return dp[index][leftsum] = (helper(v, n, leftsum + v[index], rightsum, index + 1, dp) || helper(v, n, leftsum, rightsum + v[index], index + 1, dp));
        }
    }

public:
    int equalPartition(int N, int arr[])
    {
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            v.push_back(arr[i]);
        }
        int sum = accumulate(arr, arr + N, 0);
        if (sum % 2)
            return 0;
        vector<vector<int>> dp(N, vector<int>(sum, -1));
        return helper(v, N, 0, 0, 0, dp);
    }
};

// Using Recursion - Approach #3
class Solution
{
    bool helper(int arr[], const int &n, int leftsum, int rightsum, int index)
    {
        if (index == n)
        {
            return leftsum == rightsum;
        }
        else
        {
            return helper(arr, n, leftsum + arr[index], rightsum, index + 1) || helper(arr, n, leftsum, rightsum + arr[index], index + 1);
        }
    }

public:
    int equalPartition(int N, int arr[])
    {
        sort(arr, arr + N);
        return helper(arr, N, 0, 0, 0);
    }
};
// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends