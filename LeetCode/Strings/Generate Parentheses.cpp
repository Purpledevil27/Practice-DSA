// https://leetcode.com/problems/generate-parentheses/

/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]

Constraints:

1 <= n <= 8

*/
#include <bits/stdc++.h>
using namespace std;

// Simple approach
class Solution
{
public:
    void backtracking(int open, int close, string s, vector<string> &vec, int size)
    {
        if (size * 2 == s.length())
        {
            vec.push_back(s);
            return;
        }

        if (open < size)
        {
            backtracking(open + 1, close, s + '(', vec, size);
        }
        if (close < open)
        {
            backtracking(open, close + 1, s + ')', vec, size);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> vec;
        backtracking(0, 0, "", vec, n);
        return vec;
    }
};

// Another Approach
class Solution
{
public:
    void backtracking(int rem_open, int close, string s, vector<string> &vec, int size)
    {
        if (size * 2 == s.length())
        {
            vec.push_back(s);
            return;
        }

        if (rem_open == 0)
        {
            backtracking(rem_open, close - 1, s + ')', vec, size);
            return;
        }

        backtracking(rem_open - 1, close + 1, s + '(', vec, size);

        if (rem_open == size || close == 0)
        {
            return;
        }

        backtracking(rem_open, close - 1, s + ')', vec, size);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> vec;
        backtracking(n, 0, "", vec, n);
        return vec;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution obj;
    vector<string> ans = obj.generateParenthesis(n);
    return 0;
}