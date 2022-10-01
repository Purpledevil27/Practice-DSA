// https://leetcode.com/problems/find-k-closest-elements/

/*Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

Constraints:
1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-10^4 <= arr[i], x <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size(), right = lower_bound(arr.begin(), arr.end(), x) - arr.begin(), left = right - 1;
        while (k--)
        {
            if (right >= n || left >= 0 && abs(arr[right] - x) >= abs(arr[left] - x))
                left--;
            else
                right++;
        }
        // cout << left<< " " << right << endl;
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};