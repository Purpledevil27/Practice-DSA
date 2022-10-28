// https://leetcode.com/problems/merge-k-sorted-lists/

/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []

Constraints:
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
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
    void mergeList(ListNode *&list1, ListNode *&list2, ListNode *&o)
    {
        ListNode *tail = NULL;
        if (list1 == NULL && list2 == NULL)
        {
            o = NULL;
            return;
        }
        if (list1 == NULL)
        {
            o = list2;
            return;
        }
        else if (list2 == NULL)
        {
            o = list1;
            return;
        }

        if (list1->val < list2->val)
        {
            o = list1;
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            o = list2;
            tail = list2;
            list2 = list2->next;
        }

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }
        if (list1)
        {
            tail->next = list1;
        }
        else if (list2)
        {
            tail->next = list2;
        }
    }

    void merge(vector<ListNode *> &lists, int i, int j, ListNode *&output)
    {
        if (i == j)
        {
            ListNode *t = lists[i];
            output = t;
            return;
        }

        if (abs(i - j) == 1)
        {
            mergeList(lists[i], lists[j], output);
            return;
        }

        int mid = (i + j) / 2;

        ListNode *o1 = NULL, *o2 = NULL;

        merge(lists, i, mid, o1);
        merge(lists, mid + 1, j, o2);

        mergeList(o1, o2, output);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return NULL;
        }
        ListNode *output = NULL;
        merge(lists, 0, lists.size() - 1, output);
        return output;
    }
};