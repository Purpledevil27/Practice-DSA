// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1/#

/*
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators
will only include the basic arithmetic operators like *, /, + and -.

Example 1:

Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression,
we have -4 as result.
Example 2:

Input: S = "123+*8-"
Output: -3
Explanation:
After solving the given postfix
expression, we have -3 as result.

Your Task:
You do not need to read input or print anything. Complete the function evaluatePostfixExpression() that takes the string S denoting the expression as input parameter and returns the evaluated value.

Expected Time Complexity: O(|S|)
Expected Auixilliary Space: O(|S|)

Constraints:
1 ≤ |S| ≤ 10^5

0 ≤ |Si|≤ 9 (And given operators)
*/

// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        stack<int> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                st.push(s[i] - '0');
            }
            else
            {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int res = 0;
                switch (s[i])
                {
                case '+':
                    res = op2 + op1;
                    break;
                case '-':
                    res = op2 - op1;
                    break;
                case '/':
                    res = op2 / op1;
                    break;
                case '*':
                    res = op2 * op1;
                    break;
                }
                st.push(res);
            }
        }
        return st.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;

        cout << obj.evaluatePostfix(S) << endl;
    }
    return 0;
}
// } Driver Code Ends