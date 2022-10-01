// https://practice.geeksforgeeks.org/problems/fitting-the-array1514/1

/*
Geek is playing an array game. He is weak in the concepts of arrays. Geek is given two arrays arr[ ] and brr[ ] of the same size n.
The array arr[ ] will be said to fit in array brr[ ] if by arranging the elements of both arrays, there exists a solution such that i'th element of arr[ ] is less than or equal to i'th element of brr[ ], for each i, 0 <= i < n.
Help Geek find if the given array arr[ ] will fit in array brr[ ] or not.

Example 1:

Input: arr[] = {7, 5, 3, 2},
       brr[] = {5, 4, 8, 7} and n = 4
Output: YES
Explanation: Transform arr[] = {2, 3, 5, 7} and brr[] = {4, 5, 7, 8}. Now, 2<=4, 3<=5, 5<=7 and 7<=8. So arr[] array will fit in brr[] array.

Example 2:

Input: arr[] = {1, 2, 4},
       brr[] = {1, 2, 3} and n = 3
Output: NO
Explanation: As 1<=1, 2<=2 but 4>3 so, arr[] array will not fit in brr[] array.

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function isFit() that takes an array arr[], another array brr[], size of the array n and returns true if array arr[ ] fit in array brr[ ] otherwise returns false. The driver code takes care of the printing.

Expected Time Complexity: O(N*log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 10^5
0 ≤ a[i], b[i] ≤ 10^5
*/

//{ Driver Code Starts
/* Driver program to test above function */
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++
class Solution
{
public:
    bool isFit(int arr[], int brr[], int n)
    {
        sort(arr, arr + n);
        sort(brr, brr + n);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > brr[i])
                return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int i, j, z, t, n, flag;
    cin >> t;
    for (z = 0; z < t; z++)
    {
        flag = 0;
        cin >> n;
        int arr[n + 1], brr[n + 1];

        for (i = 0; i < n; i++)
            cin >> arr[i];
        for (i = 0; i < n; i++)
            cin >> brr[i];

        Solution ob;

        if (ob.isFit(arr, brr, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends