// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1?page=2&sortBy=submissions

/*Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.

Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in the union.

Example 1:

Input:
5 3
1 2 3 4 5
1 2 3
Output: 5
Explanation: 1, 2, 3, 4 and 5 are the elements which comes in the union set of both arrays. So count is 5.

Example 2:

Input: 6 2
85 25 1 32 54 6
85 2
Output: 7
Explanation: 85, 25, 1, 32, 54, 6, and 2 are the elements which comes in the union set of both arrays. So count is 7.

Your Task:
Complete doUnion funciton that takes a, n, b, m as parameters and returns the count of union elements of the two arrays. The printing is done by the driver code.

Constraints:
1 ≤ n, m ≤ 10^5
0 ≤ a[i], b[i] < 10^5
Elements are not necessarily distinct.

Expected Time Complexity : O((n+m)log(n+m))
Expected Auxilliary Space : O(n+m)
*/

// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++
#include <unordered_map>
class Solution
{
public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(int a1[], int n, int a2[], int m)
    {
        unordered_map<int, int> ourMap;
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (ourMap.count(a1[i]) > 0)
            {
                continue;
            }
            ourMap[a1[i]] = 1;
            ind++;
        }
        for (int i = 0; i < m; i++)
        {
            if (ourMap.count(a2[i]) > 0)
            {
                continue;
            }
            ourMap[a2[i]] = 1;
            ind++;
        }
        return ind;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.doUnion(a, n, b, m) << endl;
    }

    return 0;
} // } Driver Code Ends