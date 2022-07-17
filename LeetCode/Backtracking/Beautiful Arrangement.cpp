// https://leetcode.com/problems/beautiful-arrangement/

/*Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

Example 1:

Input: n = 2
Output: 2
Explanation:
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1

Example 2:

Input: n = 1
Output: 1

Constraints:
1 <= n <= 15
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
    int count(int n, vector<int> &v)
    {
        if (n <= 0)
            return 1;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] % n == 0 || n % v[i] == 0)
            {
                swap(v[i], v[n - 1]);
                ans += count(n - 1, v);
                swap(v[i], v[n - 1]);
            }
        }
        return ans;
    }

public:
    int countArrangement(int n)
    {
        vector<int> v(n);
        for (int i = 1; i <= n; i++)
        {
            v[i - 1] = i;
        }
        int ans = count(n, v);
        return ans;
    }
};

// Approach #2
class Solution
{
    void solve(const int &n, vector<int> &v, int &ans, int curr)
    {
        if (curr == n + 1)
        {
            ans++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == 0 && (i % curr == 0 || curr % i == 0))
            {
                v[i] = 1;
                solve(n, v, ans, curr + 1);
                v[i] = 0;
            }
        }
    }

public:
    int countArrangement(int n)
    {
        int ans = 0;
        vector<int> v(n + 1, 0);
        solve(n, v, ans, 1);
        return ans;
    }
};