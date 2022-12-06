// https://leetcode.com/problems/odd-even-linked-list/description/

/*Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

Constraints:
The number of nodes in the linked list is in the range [0, 10^4].
-10^6 <= Node.val <= 10^6
*/

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *evenHead = head->next;
        ListNode *odd = head, *even = head->next;

        while (odd->next && even->next)
        {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

// JAVA SOLUTION
/*
class Solution
{
public
    ListNode oddEvenList(ListNode head)
    {
        if (head == null || head.next == null)
        {
            return head;
        }

        ListNode even_head = head.next;
        ListNode odd_tail = head;
        ListNode even_tail = head.next;

        while (odd_tail.next != null && even_tail.next != null)
        {
            odd_tail.next = odd_tail.next.next;
            odd_tail = odd_tail.next;
            even_tail.next = even_tail.next.next;
            even_tail = even_tail.next;
        }

        odd_tail.next = even_head;
        return head;
    }
}
*/
