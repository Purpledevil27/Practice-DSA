// https://leetcode.com/problems/merge-two-sorted-lists/

/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []

Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }
        if (list1->val < list2->val)
        {
            head = list1;
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            tail = list2;
            list2 = list2->next;
        }
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if (list1)
        {
            tail->next = list1;
        }
        else if (list2)
        {
            tail->next = list2;
        }
        return head;
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
    ListNode *list2 = takeInput();
    Solution obj;
    ListNode *head = obj.mergeTwoLists(list1, list2);
    print(head);
    return 0;
}