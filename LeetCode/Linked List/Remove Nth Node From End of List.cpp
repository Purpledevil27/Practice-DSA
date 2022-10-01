// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/*Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
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
    int length(ListNode *head)
    {
        int count = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = length(head);
        // if the node is at the beginning
        if (n == len)
        {
            return head->next;
        }
        // if the node is at the end
        else if (n == 1)
        {
            ListNode *ans = head;
            ListNode *prev = NULL;
            while (head->next != NULL)
            {
                prev = head;
                head = head->next;
            }
            prev->next = NULL;
            return ans;
        }
        // if the node is at the middle
        else
        {
            ListNode *ans = head;
            ListNode *prev = NULL;
            int p = len - n;
            while (p--)
            {
                prev = head;
                head = head->next;
            }
            prev->next = head->next;
            return ans;
        }
    }
};