// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1?page=1&sortBy=submissions

/*
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

Example 1:

Input: N = 3 A[] = {1,2,3}
Output: -1
Explanation: Since, each element in {1,2,3} appears only once so there is no majority element.
Example 2:

Input: N = 5 A[] = {3,1,3,3,2}
Output: 3
Explanation: Since, 3 is present more than N/2 times, so it is the majority element.

Your Task:
The task is to complete the function majorityElement() which returns the majority element in the array. If no majority exists, return -1.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 10^7
0 ≤ Ai ≤ 10^6
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
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int n)
    {

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]]++;

        for (auto it : mp)
        {
            if (it.second > n / 2)
                return it.first;
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
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends