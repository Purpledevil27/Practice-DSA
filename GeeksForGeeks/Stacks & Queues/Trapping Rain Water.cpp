// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1?page=2&sortBy=submissions

/*Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.

Example 1:

Input: N = 6 arr[] = {3,0,0,2,0,4}
Output: 10

Example 2:

Input: N = 4 arr[] = {7,4,0,9}
Output: 10
Explanation: Water trapped by above block of height 4 is 3 units and above block of height 0 is 7 units. So, the total unit of water trapped is 10 units.

Example 3:

Input: N = 3 arr[] = {6,9,9}
Output: 0
Explanation: No water will be trapped.

Your Task:
You don't need to read input or print anything. The task is to complete the function trappingWater() which takes arr[] and N as input parameters and returns the total amount of water that can be trapped.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
3 < N < 10^6
0 < Ai < 10^8
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        stack<int> s; // decreasing monotonic stack
        long long ans = 0, i = 0;
        while (i < n)
        {
            if (s.empty() || arr[i] <= arr[s.top()])
            {
                s.push(i++);
            }
            else
            {
                int bar = arr[s.top()];
                s.pop();
                ans += s.empty() ? 0 : (min(arr[s.top()], arr[i]) - bar) * (i - s.top() - 1);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}
// } Driver Code Ends