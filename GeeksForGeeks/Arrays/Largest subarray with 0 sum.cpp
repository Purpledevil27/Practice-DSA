// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

/*Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input: N = 8 A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 10^5
-1000 <= A[i] <= 1000, for each valid i
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this function*/

class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        unordered_map<int, int> m;
        m[0] = 0;
        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            if (m.count(sum) != 0)
            {
                ans = max(ans, i - m[sum] + 1);
            }
            else
            {
                m[sum] = i + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends