// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

/*Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

It is guaranteed that there will be a rectangle with a sum no larger than k.

Example 1:

Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).

Example 2:

Input: matrix = [[2,2,-1]], k = 3
Output: 3

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100
-10^5 <= k <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Using ordered_set and binary search
class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &m, int k)
    {
        int res = INT_MIN, rows = m.size(), cols = m[0].size();
        for (int l = 0; l < cols; ++l)
        {
            vector<int> sums(rows);
            for (int r = l; r < cols; ++r)
            {
                for (int i = 0; i < rows; ++i)
                    sums[i] += m[i][r];
                set<int> s = {0};
                int run_sum = 0;
                for (int sum : sums)
                {
                    run_sum += sum;
                    auto it = s.lower_bound(run_sum - k);
                    if (it != end(s))
                        res = max(res, run_sum - *it);
                    s.insert(run_sum);
                }
            }
        }
        return res;
    }
};

// Adding kadane algorithm
class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &m, int k)
    {
        int res = INT_MIN, rows = m.size(), cols = m[0].size();
        for (int l = 0; l < cols; ++l)
        {
            vector<int> sums(rows);
            for (int r = l; r < cols; ++r)
            {
                int kadane = 0, max_kadane = INT_MIN;
                for (int i = 0; i < rows; ++i)
                {
                    sums[i] += m[i][r];
                    kadane = max(kadane + sums[i], sums[i]);
                    max_kadane = max(max_kadane, kadane);
                }
                if (max_kadane <= k)
                {
                    res = max(res, max_kadane);
                    continue;
                }
                set<int> s = {0};
                int run_sum = 0;
                for (int sum : sums)
                {
                    run_sum += sum;
                    auto it = s.lower_bound(run_sum - k);
                    if (it != end(s))
                        res = max(res, run_sum - *it);
                    s.insert(run_sum);
                }
            }
        }
        return res;
    }
};