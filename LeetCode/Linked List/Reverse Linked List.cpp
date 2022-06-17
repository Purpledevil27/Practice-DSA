// https://leetcode.com/problems/reverse-linked-list/

/*Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000

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

// Recursive Approach
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *temp = reverseList(head->next);
        ListNode *tail = head->next;
        tail->next = head;
        head->next = NULL;
        return temp;
    }
};

// Iterative Approach
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nex;

        while (curr)
        {
            nex = nex->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
};

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
    ListNode *head = obj.reverseList(list1);
    print(head);
    return 0;
}
