// https://leetcode.com/problems/backspace-string-compare/

/*Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
*/
#include <bits/stdc++.h>
using namespace std;

// Using stacks
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> ss, st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '#')
            {
                ss.push(s[i]);
            }
            else
            {
                if (!ss.empty())
                    ss.pop();
            }
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] != '#')
            {
                st.push(t[i]);
            }
            else
            {
                if (!st.empty())
                    st.pop();
            }
        }
        while (!ss.empty() && !st.empty())
        {
            if (ss.top() != st.top())
            {
                return false;
            }
            ss.pop();
            st.pop();
        }
        if (!ss.empty() || !st.empty())
        {
            return false;
        }
        return true;
    }
};

// Using string properties
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        string s1 = "", s2 = "";
        for (auto c : s)
        {
            if (c == '#' && !s1.empty())
                s1.pop_back();
            else if (c != '#')
                s1 += c;
        }
        for (auto c : t)
        {
            if (c == '#' && !s2.empty())
            {
                s2.pop_back();
            }
            else if (c != '#')
                s2 += c;
        }
        return s1 == s2;
    }
};

int main()
{
    string w1, w2;
    cin >> w1 >> w2;
    Solution obj;
    cout << obj.backspaceCompare(w1, w2);
    return 0;
}
