// https://leetcode.com/problems/remove-k-digits/

/*Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

Constraints:
1 <= k <= num.length <= 10^5
num consists of only digits.
num does not have any leading zeros except for the zero itself.
*/

#include <bits/stdc++.h>
using namespace std;

// Using Monotonic stack
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num == "0" || k == 0)
            return num;

        // Adding 0 for handling cases like num = 456 where numbers are already increasing but k != 0
        num = num + "0";

        // storing num in a temporary space for making changes for the result
        string temp = num;

        // Using a monotonic increasing stack, We will store only the indices of the num.
        stack<int> s;
        for (int i = 0; i < num.length() && k; i++)
        {
            if (s.size() && num[i] < num[s.top()]) // Using top element of stack as the right side of removal
            {
                int right = i - 1, left;
                while (s.size() && num[i] < num[s.top()])
                {
                    left = s.top(); // finding the left side of the removal
                    s.pop();
                }

                int rem = min(k, right - left + 1), j = right;

                while (rem && j >= left) // removing only till the left index
                {
                    // changing the character so that we can recognise removing element later.
                    // Also keeping in the mind that we do not remove the previously removed element. i.e. removing/changing the element twice.
                    if (temp[j] != '*')
                    {
                        temp[j] = '*';
                        rem--;
                        k--;
                    }
                    j--;
                }
            }
            // Removing any preceding 0's
            if (s.empty() && num[i] == '0' && i != num.length() - 1 && k)
            {
                temp[i] = '*';
                continue;
            }
            // Pushing only when stack is empty or when there are different num[]
            // We don't need to push every indices because if there is num[] = "11111110" and k=5,
            // then right = 6 (since i will be at 0, i = 7) and left = s.top() i.e. left = 0. So, rem = min(5, 6-0+1) i.e. rem = 5.
            // So it will remove/change 5 element start from right to the left side till rem!=0 or it reaches the left most side.
            if ((s.empty()) || (!s.empty() && num[s.top()] != num[i]))
            {
                s.push(i);
            }
        }

        num = "";
        // Storing result in new num. skipping all the temp[i] == '*' and adding otherwise
        for (int i = 0; i < temp.length(); i++)
        {
            if (temp[i] != '*')
            {
                num += temp[i];
            }
        }
        int i = 0;

        // Checking for any preceding 0's
        while (num[i] == '0')
            num.erase(i, 1);

        // Removing the '0' which we have adding at the beginning
        num = num.substr(0, num.length() - 1);

        return num == "" ? "0" : num;
    }
};

// Another Approach but GIVES TLE
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num == "0" || k == 0)
            return num;
        int i = 0;
        // Adding 0 for handling cases like num = 456 where numbers are already increasing but k != 0
        num = num + "0";
        stack<char> s; // using a increasing monotonic stack

        while (k && num.length())
        {
            // popping element from stack if curr number is less than top most element in the stack
            while (s.size() && k && num[i] < s.top())
            {
                s.pop();
                k--;
            }
            // Avoiding any preceding 0's
            if (s.empty() && num[i] == '0')
            {
                num.erase(i, 1);
                continue;
            }
            // pushing element in stack and removing from original num
            s.push(num[i]);
            num.erase(i, 1);
        }

        // Taking out elements from the stack and reversing it and then adding it to remaining num
        string res = "";
        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

        // reversing it
        reverse(res.begin(), res.end());

        // adding it to remaining num
        num = res + num;
        i = 0;

        // Checking for any preceding 0's
        while (num[i] == '0')
            num.erase(i, 1);

        // Removing the '0' which we have adding at the beginning
        num = num.substr(0, num.length() - 1);

        return num == "" ? "0" : num;
    }
};
