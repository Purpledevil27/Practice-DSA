// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

/*You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

Example 1:

Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW".
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.

Example 2:

Input: blocks = "WBWBBBW", k = 2
Output: 0
Explanation:
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.

Constraints:
n == blocks.length
1 <= n <= 100
blocks[i] is either 'W' or 'B'.
1 <= k <= n
*/

#include <bits/stdc++.h>
using namespace std;

// Using Sliding Window
class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int b = 0, mb = 0;
        for (int i = 0; i < blocks.size(); ++i)
        {
            b += blocks[i] == 'B';
            if (i >= k)
                b -= blocks[i - k] == 'B';
            mb = max(b, mb);
        }
        return k - mb;
    }
};

// Brute Force
class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.length(), ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int t = 0, b = 0;
            for (int j = i; j < n && b < k; j++)
            {
                if (blocks[j] == 'W')
                {
                    t++;
                }
                b++;
            }
            if (b == k)
            {
                ans = min(ans, t);
            }
        }
        return ans;
    }
};