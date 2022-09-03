// https://leetcode.com/problems/numbers-with-same-consecutive-differences/

/*Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.

Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.

You may return the answer in any order.

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.

Example 2:

Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

Constraints:
2 <= n <= 9
0 <= k <= 9
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
    void find(int num, int const &n, int const &k, int size, vector<int> &ans)
    {
        if (size == n)
        {
            ans.push_back(num);
            return;
        }

        for (int i = 0; i <= 9; i++)
        {
            // check if we can add the digit or not
            if (abs((num % 10) - i) == k)
            {
                num *= 10;
                num += i;
                find(num, n, k, size + 1, ans);
                num /= 10; // backtrack
            }
        }
    }

public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> ans;

        // starting from 1 since no leading zeros are allowed
        for (int i = 1; i <= 9; i++)
        {
            find(i, n, k, 1, ans);
        }
        return ans;
    }
};

// Approach #2
class Solution
{
public:
    vector<int> ans;
    void helper(int n, int k, int size, int num)
    {
        if (size == n)
        {
            ans.push_back(num);
            return;
        }
        int prev = num % 10;
        if (prev + k <= 9)
        {
            helper(n, k, size + 1, num * 10 + prev + k);
        }
        if (k != 0 && (prev - k) >= 0)
        {
            helper(n, k, size + 1, num * 10 + (prev - k));
        }
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        // starting from 1 since no leading zeros are allowed
        for (int i = 1; i <= 9; i++)
        {
            helper(n, k, 1, i);
        }

        return ans;
    }
};
