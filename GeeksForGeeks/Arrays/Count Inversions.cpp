// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?page=2&sortBy=submissions

/*Given an array of integers. Find the Inversion Count in the array.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum.
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Example 2:

Input: N = 5 arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.

Your Task:
You don't need to read input or print anything. Your task is to complete the function inversionCount() which takes the array arr[] and the size of the array as inputs and returns the inversion count of the given array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
#define ll long long
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll countInversions(ll *arr, int start, int end)
    {
        // Base case
        if (start >= end)
            return 0;

        int mid = start + ((end - start) / 2);
        ll leftCount = countInversions(arr, start, mid);
        ll rightCount = countInversions(arr, mid + 1, end);
        ll total = leftCount + rightCount;

        // Create a new sorted array.
        int size = end - start + 1;
        ll *sorted_arr = new ll[size];
        int i = 0, j = start, k = mid + 1;

        while (j <= mid && k <= end)
        {
            if (arr[j] <= arr[k])
            {
                // arr[start] will be less than all the elements of the right
                sorted_arr[i++] = arr[j++];
            }
            else
            {
                total += (mid - j + 1);
                sorted_arr[i++] = arr[k++];
            }
        }
        while (j <= mid)
            sorted_arr[i++] = arr[j++];
        while (k <= end)
            sorted_arr[i++] = arr[k++];

        // Copy back elements from the new array to original array
        for (int i = 0; i < size; i++)
        {
            arr[start + i] = sorted_arr[i];
        }

        delete sorted_arr;

        return total;
    }

    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return countInversions(arr, 0, N - 1);
    }
};

//{ Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends