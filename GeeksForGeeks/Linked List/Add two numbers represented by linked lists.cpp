// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?page=3&sortBy=submissions

/*Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Example 1:
Input: N = 2 valueN[] = {4,5} M = 3 valueM[] = {3,4,5}
Output: 3 9 0
Explanation: For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).

Example 2:
Input: N = 2 valueN[] = {6,3} M = 1 valueM[] = {7}
Output: 7 0
Explanation: For the given two linked list (6 3) and (7), after adding the two linked list resultant linked list will be (7 0).

Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

Constraints:
1 <= N, M <= 5000
*/

//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
class Solution
{
public:
    // Function to add two numbers represented by linked list.
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {

        first = reverse(first);
        second = reverse(second);

        Node *dummy = new Node(0);
        Node *curr = dummy;
        Node *p = first, *q = second;
        int carry = 0;
        while (p != NULL || q != NULL)
        {
            int x = (p != NULL) ? p->data : 0;
            int y = (q != NULL) ? q->data : 0;

            int sum = x + y + carry;
            curr->next = new Node(sum % 10);
            carry = sum / 10;
            curr = curr->next;

            if (p != NULL)
                p = p->next;
            if (q != NULL)
                q = q->next;
        }

        if (carry > 0)
            curr->next = new Node(carry);

        dummy = reverse(dummy->next);
        return dummy;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends