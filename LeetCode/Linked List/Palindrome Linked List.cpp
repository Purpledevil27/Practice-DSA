// https://leetcode.com/problems/palindrome-linked-list/

/*Given the head of a singly linked list, return true if it is a palindrome.

Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false

Constraints:

The number of nodes in the list is in the range [1, 10^5].
0 <= Node.val <= 9

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

// O(N) TC & O(1) SC
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = NULL;
        while (fast && fast->next)
        {
            ListNode *rev = slow;
            slow = slow->next;
            fast = fast->next->next;

            rev->next = prev;
            prev = rev;
        }
        if (fast)
        {
            slow = slow->next;
        }
        while (prev && slow)
        {
            if (prev->val != slow->val)
            {
                return false;
            }
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};

// Using Queue and Recursion O(N) TC & O(N) SC
class Solution
{
    bool solve(ListNode *head, queue<int> &s)
    {
        if (head == NULL)
        {
            return true;
        }
        s.push(head->val);
        bool ans = solve(head->next, s);
        if (s.front() == head->val && ans)
        {
            s.pop();
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        queue<int> s;
        return solve(head, s);
    }
};

// O(N^2) TC & O(1) SC
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *tail = head->next;
        ListNode *prev = head;
        while (tail->next != NULL)
        {
            prev = tail;
            tail = tail->next;
        }
        if (head->val == tail->val)
        {
            prev->next = NULL;
            delete tail;
            return isPalindrome(head->next);
        }
        else
        {
            return false;
        }
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
    cout << obj.isPalindrome(list1);
    return 0;
}
