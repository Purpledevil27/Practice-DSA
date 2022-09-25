// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1?page=3&sortBy=submissions

/*Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Example 1:

Input: N = 7 a[] = {2,6,1,9,4,5,3}
Output: 6
Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.

Example 2:

Input: N = 7 a[] = {1,9,3,10,4,20,2}
Output: 4
Explanation: 1, 2, 3, 4 is the longest consecutive subsequence.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findLongestConseqSubseq() which takes the array arr[] and the size of the array as inputs and returns the length of the longest subsequence of consecutive integers.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 10^5
0 <= a[i] <= 10^5
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        set<int> s;
        int len = 1;
        int max_len = 1;
        for (int i = 0; i < N; i++)
            s.insert(arr[i]);
        for (auto &x : s)
        {
            if (*(s.upper_bound(x)) == x + 1)
            {
                len++;
                max_len = max(max_len, len);
            }
            else
            {
                len = 1;
            }
        }
        return max_len;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}
// } Driver Code Ends