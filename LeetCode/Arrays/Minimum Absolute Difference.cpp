// https://leetcode.com/problems/minimum-absolute-difference/

/*Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr

Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.

Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]

Example 3:

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]

Constraints:
2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        vector<vector<int>> result;
        int min_diff = INT_MAX;

        // find min difference
        for (int i = 0; i < arr.size() - 1; ++i)
        {
            min_diff = min(arr[i + 1] - arr[i], min_diff);
        }

        // form a list of pairs with min difference, ascending
        for (int i = 0; i < arr.size() - 1; ++i)
        {
            if (arr[i + 1] - arr[i] == min_diff)
                result.push_back({arr[i], arr[i + 1]});
        }
        return result;
    }
};