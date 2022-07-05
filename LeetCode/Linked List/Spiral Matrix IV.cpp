// https://leetcode.com/problems/spiral-matrix-iv/

/*You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

Example 1:

Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.

Example 2:

Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.

Constraints:

1 <= m, n <= 10^5
1 <= m * n <= 10^5
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000

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

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> spiralMatrix(int row, int col, ListNode *head)
    {
        vector<vector<int>> m(row, vector<int>(col, -1));
        int i = 0, j = 0, step = 0;

        // if head==NULL, that means that we have covered all the nodes
        while (head != NULL)
        {
            // we will move to the top - rightmost for loop 1
            while (j < col - step && head != NULL)
            {
                m[i][j] = head->val;
                j++;
                head = head->next;
            }
            // adjusting the positions for the next line
            j--;
            i++;

            // moving to the bottom rightmost for loop 1
            while (i < row - step && head != NULL)
            {
                m[i][j] = head->val;
                i++;
                head = head->next;
            }
            // adjusting the positions for the next line
            i--;
            j--;

            // moving to the bottom leftmost for loop 1
            while (j >= step && head != NULL)
            {
                m[i][j] = head->val;
                j--;
                head = head->next;
            }
            // adjusting the positions for the next line
            j++;
            i--;

            // moving back to the (top-1) leftmost i.e. not going to (0,0) again, but stopping at (1,0)
            while (i > step && head != NULL)
            {
                m[i][j] = head->val;
                i--;
                head = head->next;
            }
            // adjusting the positions for the next line
            i++;
            j++;

            // step will take care of how many side to ignore for every loop.
            // i.e. in the next step, it will not move to the rightmost or till the bottom, it will at stop one side earlier in the next loop
            step++;
        }
        return m;
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
    int row, col;
    cin >> row >> col;
    ListNode *list1 = takeInput();
    Solution obj;
    vector<vector<int>> ans = obj.spiralMatrix(row, col, list1);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
