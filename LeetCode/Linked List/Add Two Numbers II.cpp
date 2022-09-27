// https://leetcode.com/problems/add-two-numbers-ii/

/*You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;
        // pushing the number 1 in the stack
        while (l1 != NULL)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        // pushing number 2 in the stack
        while (l2 != NULL)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *ans = NULL;
        int car = 0;
        // Computing num till one of the stack is empty
        while (!s1.empty() && !s2.empty())
        {
            int n1 = s1.top(), n2 = s2.top();
            s2.pop();
            s1.pop();
            int sum = n1 + n2 + car;
            car = sum / 10;
            sum %= 10;
            ListNode *t = new ListNode(sum);
            t->next = ans;
            ans = t;
        }
        // looking for remaining digit in number 2
        while (!s2.empty())
        {
            int sum = s2.top() + car;
            car = sum / 10;
            sum %= 10;
            ListNode *t = new ListNode(sum);
            t->next = ans;
            ans = t;
            s2.pop();
        }
        // looking for remaining digit in number 1
        while (!s1.empty())
        {
            int sum = s1.top() + car;
            car = sum / 10;
            sum %= 10;
            ListNode *t = new ListNode(sum);
            t->next = ans;
            ans = t;
            s1.pop();
        }
        // looking for any carry left from additions before
        if (car > 0)
        {
            ListNode *t = new ListNode(car);
            t->next = ans;
            ans = t;
        }
        return ans;
    }
};