// https://leetcode.com/problems/valid-parentheses/

/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Constraints:

1 <= s.length <= 10^4
s consists of parentheses only '()[]{}'.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                    continue;
                }
                return false;
            }

            else if (s[i] == '}')
            {
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                    continue;
                }
                return false;
            }
            else if (s[i] == ']')
            {
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                    continue;
                }
                return false;
            }
        }
        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.isValid(s);
    return 0;
}