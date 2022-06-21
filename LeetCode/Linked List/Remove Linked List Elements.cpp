// https://leetcode.com/problems/remove-linked-list-elements/

/*Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []

Constraints:

The number of nodes in the list is in the range [0, 10^4].
1 <= Node.val <= 50
0 <= val <= 50

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
    ListNode *removeElements(ListNode *head, int val)
    {
        // Base case
        if (head == NULL)
        {
            return head;
        }

        // Recursion call
        head->next = removeElements(head->next, val);

        // If the head value and given number is same returning head->next.
        if (head->val == val)
        {
            return head->next;
        }
        // else just return head.
        return head;

        // You can also write above if-else in one line
        // return head->val == val ? head->next : head;
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
    ListNode *head = takeInput();
    int x;
    cin >> x;
    Solution obj;
    ListNode *mid = obj.removeElements(head, x);
    print(mid);
    return 0;
}