// https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1?page=2&sortBy=submissions

/*Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero.

Example 1:
Input: n = 5, arr[] = {0, -1, 2, -3, 1}
Output: 1
Explanation: 0, -1 and 1 forms a triplet with sum equal to 0.

Example 2:
Input: n = 3, arr[] = {1, 2, 3}
Output: 0
Explanation: No triplet with zero sum exists.

Your Task:
You don't need to read input or print anything. Your task is to complete the boolean function findTriplets() which takes the array arr[] and the size of the array (n) as inputs and print 1 if the function returns true else print 0 if the function returns false.

Expected Time Complexity: O(n^2)
Expected Auxiliary Space: O(1)

Constrains:
1 <= n <= 10^4
-10^6 <= Ai <= 10^6
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
 *  arr[]: input array
 *  n: size of array
 */
class Solution
{
public:
    // Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    {
        sort(arr, arr + n);
        int sum = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int r = n - 1;
            while (j < r)
            {
                sum = arr[i] + arr[j] + arr[r];
                if (sum == 0)
                    return 1;
                if (sum < 0)
                    j++;
                else
                    r--;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n] = {0};
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        if (obj.findTriplets(arr, n))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}
// } Driver Code Ends