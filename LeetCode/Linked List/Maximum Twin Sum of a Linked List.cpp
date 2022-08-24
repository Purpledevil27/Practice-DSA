// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

/*In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

Example 1:

Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6.

Example 2:

Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7.

Example 3:

Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.

Constraints:
The number of nodes in the list is an even integer in the range [2, 10^5].
1 <= Node.val <= 10^5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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

// Reversing the first half of the linked list
class Solution
{
    int length(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

public:
    int pairSum(ListNode *head)
    {
        int len = length(head);
        int step = len / 2;
        ListNode *mid = head;
        while (step--)
        {
            mid = mid->next;
        }

        ListNode *prev = NULL, *temp = NULL, *curr = head;

        while (curr != mid)
        {
            temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
        }

        int ans = INT_MIN;
        while (curr)
        {
            ans = max(ans, temp->val + curr->val);
            curr = curr->next;
            temp = temp->next;
        }
        return ans;
    }
};

// Using Stack
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        stack<int> s;
        ListNode *temp = head;
        int step = 0;
        while (temp)
        {
            step++;
            s.push(temp->val);
            temp = temp->next;
        }
        step /= 2;
        int ans = INT_MIN;
        while (step--)
        {
            ans = max(ans, (head->val + s.top()));
            s.pop();
            head = head->next;
        }
        return ans;
    }
};