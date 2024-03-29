// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1?page=1&sortBy=submissions

/*
Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Example 1:

Input: N = 2 LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there are 9 nodes in linked list and we need to find 2nd node from end. 2nd node from end os 8.

Example 2:

Input: N = 5 LinkedList: 10->5->100->5
Output: -1
Explanation: In the second example, there are 4 nodes in the linked list and we need to find 5th from the end. Since 'n' is more than the number of nodes in the linked list, the output is -1.

Your Task:
The task is to complete the function getNthFromLast() which takes two arguments: reference to head and N and you need to return Nth from the end or -1 in case node doesn't exist..

Note: Try to solve in single traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= L <= 10^6
1 <= N <= 10^6
*/

//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node *head, int n);

/* Driver program to test above function*/
int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n >> k;
        int firstdata;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        cout << getNthFromLast(head, k) << endl;
    }
    return 0;
}
// } Driver Code Ends

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to find the data of nth node from the end of a linked list.
// Approach #1
int getNthFromLast(Node *head, int n)
{
    Node *slow = head, *fast = head;
    while (n != 0)
    {
        fast = fast->next;
        n--;
        // when n is greater than the length of the linked list
        if (fast == NULL && n != 0)
        {
            return -1;
        }
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}

// Appraoch #2
int sizeOfLL(Node *head)
{
    int sz = 0;

    while (head != NULL)
    {
        ++sz;
        head = head->next;
    }

    return sz;
}

int getNthFromLast(Node *head, int n)
{
    int size = sizeOfLL(head);

    if (n > size)
        return -1;

    n = size - n; // ex - n = 2, size = 8, size - n = 6 (that we actually need)

    for (int i = 0; i < n; ++i)
    {
        head = head->next;
    }

    return head->data;
}