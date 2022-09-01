// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1?page=1&sortBy=submissions

/*
Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Example 1:

Input:
N = 6 arr[] = 7 10 4 3 20 15 K = 3
Output : 7
Explanation : 3rd smallest element in the given array is 7.
Example 2:

Input:
N = 5 arr[] = 7 10 4 20 15 K = 4
Output : 15
Explanation : 4th smallest element in the given array is 15.

Your Task:
You don't have to read input or print anything. Your task is to complete the function kthSmallest() which takes the array arr[], integers l and r denoting the starting and ending index of the array and an integer K as input and returns the Kth smallest element.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(log(n))
Constraints:
1 <= N <= 10^5
1 <= arr[i] <= 10^5
1 <= K <= N
*/

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> p;

        for (int i = 0; i < k; i++)
        {
            p.push(arr[i]);
        }

        for (int i = k; i <= r; i++)
        {
            if (arr[i] < p.top())
            {
                p.pop();
                p.push(arr[i]);
            }
        }

        return p.top();
    }
};

//{ Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
}
// } Driver Code Ends