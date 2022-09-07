// https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1?page=3&sortBy=submissions

/*Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:
Input: N = 5 value[] = {2, 4, 7, 8, 9} k = 3
Output: 8 9 2 4 7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

Example 2:

Input: N = 8 value[] = {1, 2, 3, 4, 5, 6, 7, 8} k = 4
Output: 5 6 7 8 1 2 3 4

Your Task:
You don't need to read input or print anything. Your task is to complete the function rotate() which takes a head reference as the first argument and k as the second argument, and returns the head of the rotated linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^3
1 <= k <= N

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

// } Driver Code Ends
class Solution
{
    int len(Node *head)
    {
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

public:
    // Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        if (head == NULL || head->next == NULL || len(head) == k)
            return head;
        Node *ans = head;
        Node *ansprev = NULL;
        Node *tail = head;
        int t = k - 1;
        while (k--)
        {
            ansprev = ans;
            ans = ans->next;
        }
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = head;
        ansprev->next = NULL;
        return ans;
    }
};

//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, val, k;
        cin >> n;

        cin >> val;
        Node *head = new Node(val);
        Node *tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        cin >> k;

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends