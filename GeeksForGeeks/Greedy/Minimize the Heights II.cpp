// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1?page=1&sortBy=submissions

/*Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

Example 1:

Input: K = 2, N = 4 Arr[] = {1, 5, 8, 10}
Output: 5
Explanation: The array can be modified as {3, 3, 6, 8}. The difference between the largest and the smallest is 8-3 = 5.

Example 2:

Input: K = 3, N = 5 Arr[] = {3, 9, 12, 16, 20}
Output: 11
Explanation:
The array can be modified as {6, 12, 9, 13, 17}. The difference between the largest and the smallest is 17-6 = 11.

Your Task:
You don't need to read input or print anything. Your task is to complete the function getMinDiff() which takes the arr[], n, and k as input parameters and returns an integer denoting the minimum difference.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(N)

Constraints
1 ≤ K ≤ 10^4
1 ≤ N ≤ 10^5
1 ≤ Arr[i] ≤ 10^5

*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {

        if (n == 1)
            return 0;

        sort(arr, arr + n);

        int diff = arr[n - 1] - arr[0];

        for (int i = 1; i < n; i++)
        {
            if (arr[i] - k < 0)
                continue;

            int maxx = max(arr[i - 1] + k, arr[n - 1] - k);
            int minn = min(arr[0] + k, arr[i] - k);

            diff = min(diff, maxx - minn);
        }
        return diff;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends