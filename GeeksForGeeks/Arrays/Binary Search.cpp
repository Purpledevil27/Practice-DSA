// https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1?page=1&sortBy=submissions

/*Given a sorted array of size N and an integer K, find the position at which K is present in the array using binary search.

Example 1:

Input: N = 5 arr[] = {1 2 3 4 5} K = 4
Output: 3
Explanation: 4 appears at index 3.

Example 2:

Input: N = 5 arr[] = {11 22 33 44 55} K = 445
Output: -1
Explanation: 445 is not present.

Your Task:
You dont need to read input or print anything. Complete the function binarysearch() which takes arr[], N and K as input parameters and returns the index of K in the array. If K is not present in the array, return -1.

Expected Time Complexity: O(LogN)
Expected Auxiliary Space: O(LogN) if solving recursively and O(1) otherwise.

Constraints:
1 <= N <= 10^5
1 <= arr[i] <= 10^6
1 <= K <= 10^6
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
    int binarysearch(int arr[], int n, int k)
    {
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] == k)
            {
                return mid;
            }
            else if (arr[mid] < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
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
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends