// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?page=2&sortBy=submissions

/*
Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader.

Example 1:

Input: n = 6 A[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: The first leader is 17 as it is greater than all the elements to its right.  Similarly, the next leader is 5. The right most element is always a leader so it is also included.


Example 2:
Input: n = 5 A[] = {1,2,3,4,0}
Output: 4 0

Your Task:
You don't need to read input or print anything. The task is to complete the function leader() which takes array A and n as input parameters and returns an array of leaders in order of their appearance.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 10^7
0 <= Ai <= 10^7
*/

//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int a[], int n)
    {
        // Code here
        vector<int> ans;
        int maax = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] >= maax)
            {
                maax = a[i];
                ans.push_back(maax);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;
    cin >> t; // testcases
    while (t--)
    {
        long long n;
        cin >> n; // total size of array

        int a[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(a, n);

        // printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout << *it << " ";
        }

        cout << endl;
    }
}

// } Driver Code Ends