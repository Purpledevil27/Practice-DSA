// https://leetcode.com/problems/reverse-linked-list-ii/

/*Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]

Constraints:
The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
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
    ListNode *successor = NULL;
    ListNode *reverseN(ListNode *head, int n)
    {
        if (n == 1)
        {
            successor = head->next;
            return head;
        }
        ListNode *last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (m == 1)
        {
            return reverseN(head, n);
        }
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }
};

// Drivers Code
ListNode *takeInput()
{
    int data;
    cin >> data;
    ListNode *head = NULL;
    ListNode *tail = NULL;

    while (data != -1)
    {
        ListNode *temp = new ListNode(data);
        if (head == NULL && tail == NULL)
        {
            tail = temp;
            head = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
            // tail =temp;
        }
        cin >> data;
    }
    return head;
}

void print(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *list1 = takeInput();
    Solution obj;
    int left, right;
    cin >> left >> right;
    ListNode *head = obj.reverseBetween(list1, left, right);
    print(head);
    return 0;
}
