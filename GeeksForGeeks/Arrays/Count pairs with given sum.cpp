// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1?page=2&sortBy=submissions

/*Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

Example 1:
Input: N = 4, K = 6 arr[] = {1, 5, 7, 1}
Output: 2
Explanation: arr[0] + arr[1] = 1 + 5 = 6 and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:

Input: N = 4, K = 2 arr[] = {1, 1, 1, 1}
Output: 6
Explanation: Each 1 will produce sum 2 with any 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function getPairsCount() which takes arr[], n and k as input parameters and returns the number of pairs that have sum K.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 10^5
1 <= K <= 10^8
1 <= Arr[i] <= 10^6
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
    int getPairsCount(int a[], int n, int k)
    {
        int count = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int diff = k - a[i];
            if (mp.find(diff) != mp.end()) // present
                count += mp[diff];
            mp[a[i]]++;
        }
        return count;
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
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
}
// } Driver Code Ends