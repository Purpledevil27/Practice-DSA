// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

/*Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n^2).

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Example 2:

Input: matrix = [[-5]], k = 1
Output: -5

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 10^9
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n^2
*/

#include <bits/stdc++.h>
using namespace std;

// Using Binary Search - TC - O(N) || SC - O(1)
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int ans = INT_MAX;
        while (low <= high)
        {
            int c = 0;
            int mid = low + (high - low) / 2;

            for (int i = 0; i < n; i++)
            {
                c += (upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin());
            }

            if (c < k)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};

// Using Heaps - Priority Queue
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = matrix.size();
        int index = (n * n) - k + 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pq.size() >= index)
                {
                    if (pq.top() < matrix[i][j])
                    {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
                else
                    pq.push(matrix[i][j]);
            }
        }
        return pq.top();
    }
};