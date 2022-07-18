// https://leetcode.com/problems/the-kth-factor-of-n/

/*You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

Example 1:

Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.

Example 2:

Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.

Example 3:

Input: n = 4, k = 4
Output: -1
Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.

Constraints:
1 <= k <= n <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    int kthFactor(int n, int k)
    {
        int ans = -1;
        for (int i = 1; i <= n and k != 0; i++)
        {
            if (n % i == 0)
            {
                ans = i;
                k--;
            }
        }

        return k == 0 ? ans : -1;
    }
};

// Approach #2
class Solution
{
    vector<int> findfactors(int n)
    {
        vector<int> a;
        for (int i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                if (n / i == i)
                {
                    a.push_back(i);
                }
                else
                {
                    a.push_back(i);
                    a.push_back(n / i);
                }
            }
        }
        return a;
    }

public:
    int kthFactor(int n, int k)
    {
        vector<int> v = findfactors(n);
        sort(v.begin(), v.end());
        if (k > v.size())
            return -1;
        return v[k - 1];
    }
};