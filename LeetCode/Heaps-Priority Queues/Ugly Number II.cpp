// https://leetcode.com/problems/ugly-number-ii/

/*An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

Constraints:
1 <= n <= 1690
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int dp[n];
        int t2 = 0, t3 = 0, t5 = 0;
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i] = min(dp[t2] * 2, min(dp[t3] * 3, dp[t5] * 5));
            if (dp[t2] * 2 == dp[i])
                t2++;
            if (dp[t3] * 3 == dp[i])
                t3++;
            if (dp[t5] * 5 == dp[i])
                t5++;
        }
        return dp[n - 1];
    }
};

class Solution
{
    void push_ele(long long num, priority_queue<long long, vector<long long>, greater<long long>> &n, unordered_map<long long, long long> &m)
    {
        if (m.count(num) == 0)
        {
            n.push(num);
            m[num]++;
        }
    }

public:
    long long nthUglyNumber(long long n)
    {
        priority_queue<long long> maxheap;
        priority_queue<long long, vector<long long>, greater<long long>> minheap, n2, n3, n5;
        unordered_map<long long, long long> m;
        maxheap.push(1);
        minheap.push(1);
        m[1]++;

        while (maxheap.size() < n)
        {
            long long front = minheap.top();
            minheap.pop();
            long long num2 = front * 2;
            long long num3 = front * 3;
            long long num5 = front * 5;
            push_ele(num2, n2, m);
            push_ele(num3, n3, m);
            push_ele(num5, n5, m);
            long long mi = min(n2.top(), min(n3.top(), n5.top()));
            if (n2.top() < n3.top() && n2.top() < n5.top())
            {
                n2.pop();
            }
            else if (n3.top() < n2.top() && n3.top() < n5.top())
            {
                n3.pop();
            }
            else if (n5.top() < n2.top() && n5.top() < n3.top())
            {
                n5.pop();
            }
            minheap.push(mi);
            maxheap.push(mi);
        }
        return maxheap.top();
    }
};

// Drivers Code
int main()
{
    int n;
    cin >> n;
    Solution obj;
    cout << obj.nthUglyNumber(n);
    return 0;
}