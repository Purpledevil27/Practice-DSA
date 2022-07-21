// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

/*Given the mobile numeric keypad. You can only press buttons that are up, left, right, or down to the current button. You are not allowed to press bottom row corner buttons (i.e. * and # ). Given a number N, the task is to find out the number of possible numbers of the given length.

Example 1:

Input: 1
Output: 10
Explanation: Number of possible numbers would be 10 (0, 1, 2, 3, …., 9)

Example 2:

Input: N = 2
Output: 36
Explanation: Possible numbers: 00, 08, 11, 12, 14, 22, 21, 23, 25 and so on.
If we start with 0, valid numbers will be 00, 08 (count: 2)
If we start with 1, valid numbers will be 11, 12, 14 (count: 3)
If we start with 2, valid numbers will be 22, 21, 23,25 (count: 4)
If we start with 3, valid numbers will be 33, 32, 36 (count: 3)
If we start with 4, valid numbers will be 44,41,45,47 (count: 4)
If we start with 5, valid numbers will be 55,54,52,56,58 (count: 5)
and so on..

Your Task:
You don't need to read input or print anything. Complete the function getCount() which takes N as input parameter and returns the integer value

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 25
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long getCount(int N)
    {
        if (N == 1)
            return 10;
        vector<long long> dp1(10, 1), dp2(10, 0);
        // vector<vector<int>> ms = ({0, 8}, {1, 2, 4}, {2, 1, 3, 5},{3, 2, 6}, {4, 1, 5, 7}, {5, 2, 4, 6, 8}, {6, 3, 5,9}, {7, 4, 8}, {8, 5, 7,9 , 0}, {9, 6, 8});
        for (int i = 1; i < N; i++)
        {
            dp2[0] = (dp1[0] + dp1[8]);
            dp2[1] = (dp1[1] + dp1[2] + dp1[4]);
            dp2[2] = (dp1[2] + dp1[1] + dp1[3] + dp1[5]);
            dp2[3] = (dp1[3] + dp1[2] + dp1[6]);
            dp2[4] = ((dp1[4] + dp1[1]) + dp1[5] + dp1[7]);
            dp2[5] = (dp1[5] + dp1[2] + dp1[4] + dp1[6] + dp1[8]);
            dp2[6] = ((dp1[6] + dp1[5]) + dp1[3] + dp1[9]);
            dp2[7] = (dp1[8] + dp1[7] + dp1[4]);
            dp2[8] = (dp1[8] + dp1[5] + dp1[7] + dp1[9] + dp1[0]);
            dp2[9] = (dp1[9] + dp1[6] + dp1[8]);
            dp1 = dp2;
        };
        // long long unsigned ans = accumulate(dp1.begin(), dp1.end(), 0);
        long long ans = 0;
        for (int i = 0; i < 10; i++)
        {
            ans += dp1[i];
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
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends