// https://leetcode.com/problems/push-dominoes/

/*There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.

Example 1:

Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.

Example 2:

Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."

Constraints:
n == dominoes.length
1 <= n <= 10^5
dominoes[i] is either 'L', 'R', or '.'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        dominoes = 'L' + dominoes + 'R';
        string ans = "";
        for (int start = 0, end = 1; end < dominoes.length(); ++end)
        {
            if (dominoes[end] == '.')
                continue;

            int middlelength = end - start - 1;

            if (start > 0)
                ans += dominoes[start];

            if (dominoes[start] == dominoes[end])
            {
                ans += string(middlelength, dominoes[start]);
            }
            else if (dominoes[start] == 'L' && dominoes[end] == 'R')
            {
                ans += string(middlelength, '.');
            }
            else
            {
                ans += string(middlelength / 2, 'R') + string(middlelength % 2, '.') + string(middlelength / 2, 'L');
            }
            start = end;
        }
        return ans;
    }
};