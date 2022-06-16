// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

/*Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

Example 1:

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
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

// Using stoi() function to convert string to binary number
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        string s = "";
        for (auto i = head; i != NULL; i = i->next)
        {
            s += to_string(i->val);
        }
        int t = stoi(s, 0, 2);
        return t;
    }
};

// Calculation using recursion
class Solution
{
    pair<int, int> solve(ListNode *head)
    {
        if (head->next == NULL)
        {
            return {head->val, 1};
        }
        pair<int, int> ans = solve(head->next);
        return {head->val * pow(2, ans.second) + ans.first, ans.second + 1};
    }

public:
    int getDecimalValue(ListNode *head)
    {
        pair<int, int> ans = solve(head);
        return ans.first;
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
    Solution obj;
    cout << obj.getDecimalValue(head);
    return 0;
}