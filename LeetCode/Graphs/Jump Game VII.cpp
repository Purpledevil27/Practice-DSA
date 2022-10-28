// https://leetcode.com/problems/jump-game-vii/

/*You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

i + minJump <= j <= min(i + maxJump, s.length - 1), and
s[j] == '0'.
Return true if you can reach index s.length - 1 in s, or false otherwise.

Example 1:

Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3.
In the second step, move from index 3 to index 5.

Example 2:

Input: s = "01101110", minJump = 2, maxJump = 3
Output: false

Constraints:
2 <= s.length <= 10^5
s[i] is either '0' or '1'.
s[0] == '0'
1 <= minJump <= maxJump < s.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.length();
        if (s[n - 1] != '0')
            return false;

        int i = 0;
        queue<int> q;
        q.push(0);
        int curr_max = 0;

        while (!q.empty())
        {
            i = q.front();
            q.pop();
            if (i == n - 1)
                return true;

            for (int j = max(i + minJump, curr_max); j <= min(i + maxJump, n - 1); j++)
            {
                if (s[j] == '0')
                    q.push(j);
            }
            curr_max = min(i + maxJump + 1, n);
        }
        return false;
    }
};