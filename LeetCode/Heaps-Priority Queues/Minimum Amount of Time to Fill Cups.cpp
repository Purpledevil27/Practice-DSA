// https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/

/*You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.

You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold, warm,
and hot water cups you need to fill respectively. Return the minimum number of seconds needed to fill up all the cups.

Example 1:

Input: amount = [1,4,2]
Output: 4
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup and a warm cup.
Second 2: Fill up a warm cup and a hot cup.
Second 3: Fill up a warm cup and a hot cup.
Second 4: Fill up a warm cup.
It can be proven that 4 is the minimum number of seconds needed.

Example 2:

Input: amount = [5,4,4]
Output: 7
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup, and a hot cup.
Second 2: Fill up a cold cup, and a warm cup.
Second 3: Fill up a cold cup, and a warm cup.
Second 4: Fill up a warm cup, and a hot cup.
Second 5: Fill up a cold cup, and a hot cup.
Second 6: Fill up a cold cup, and a warm cup.
Second 7: Fill up a hot cup.

Example 3:

Input: amount = [5,0,0]
Output: 5
Explanation: Every second, we fill up a cold cup.

Constraints:

amount.length == 3
0 <= amount[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

// Using Simple maths
/*
1.  ans >= max(A)
    Because each time,
    one type can reduce at most 1 cup,
    so the final result is bigger or equal to max(A)

2.  ans >= ceil(sum(A) / 2)
    Because each time,
    we can fill up to 2 cups,
    so the final result is bigger or equal to ceil(sum(A) / 2)

The possible strategy is greedily fill up 2 cups with different types of water.
We pick the 2 types with the most number of cups.
*/
class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        int mx = 0, sum = 0;
        for (auto i : amount)
        {
            mx = max(mx, i);
            sum += i;
        }
        return max(mx, (sum + 1) / 2);
    }
};

// Using Priority Queue/ Sorting
class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        int count = 0;
        priority_queue<int> pq;
        for (auto i : amount)
        {
            pq.push(i);
        }
        while (!pq.empty())
        {
            int m1 = pq.top();
            pq.pop();
            int m2 = pq.top();
            pq.pop();
            if (m1 <= 0)
            {
                break;
            }
            else
            {
                count++;
                m1--;
                m2--;
                pq.push(m1);
                pq.push(m2);
            }
        }
        return count;
    }
};