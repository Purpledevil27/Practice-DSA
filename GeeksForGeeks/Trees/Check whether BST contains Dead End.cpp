// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1#

/*Given a Binary search Tree that contains positive integer values greater then 0. The task is to complete the function isDeadEnd
which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

Examples:

Input :
               8
             /   \
           5      9
         /  \
        2    7
       /
      1

Output : Yes
Explanation : Node "1" is the dead End because after that we cant insert any element.

Input :
              8
            /   \
           7     10
         /      /   \
        2      9     13

Output : Yes
Explanation : We can't insert any element at node 9.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case
consists of three lines. First line of each test case contains an integer N denoting the no of nodes of the BST . Second line of
each test case consists of 'N' space separated integers denoting the elements of the BST. These elements are inserted into BST in the given order.

Output:
The output for each test case will be 1 if the BST contains a dead end else 0.

Constraints:
1<=T<=100
1<=N<=200

Example(To be used only for expected output):
Input:
2
6
8 5 9 7 2 1
6
8 7 10 9 13 2
Output:
1
1

*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void insert(Node **tree, int val)
{
    Node *temp = NULL;
    if (!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if (val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}

int getCountOfNode(Node *root, int l, int h)
{

    if (!root)
        return 0;

    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
        return 1 + getCountOfNode(root->left, l, h) +
               getCountOfNode(root->right, l, h);

    else if (root->data < l)
        return getCountOfNode(root->right, l, h);

    else
        return getCountOfNode(root->left, l, h);
}

bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root;
        Node *tmp;
        // int i;

        root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            insert(&root, k);
        }

        cout << isDeadEnd(root);
        cout << endl;
    }
}

// } Driver Code Ends

/*You are required to complete below method */
bool solve(Node *root, int lb, int ub, bool &ans)
{
    if (root == NULL && abs(ub - lb) == 1)
    {
        return true;
    }
    if (root == NULL)
    {
        return false;
    }
    cout << root->data << endl;
    bool l = solve(root->left, lb, root->data, ans);
    bool r = solve(root->right, root->data, ub, ans);
    if (l && r)
    {
        ans = true;
    }
    return false;
}

bool isDeadEnd(Node *root)
{
    bool ans = false;
    solve(root, 0, INT_MAX, ans);
    return ans;
}