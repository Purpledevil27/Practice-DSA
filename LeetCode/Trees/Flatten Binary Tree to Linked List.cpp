// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/*Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Example 1:

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [0]
Output: [0]

Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Approach #1 - recursive approach, can be called as reverse postorder approach since we are visiting right->left->root
class Solution
{
    TreeNode *temp = NULL;

public:
    void flatten(TreeNode *root)
    {

        if (!root)
        {
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->right = temp;
        root->left = NULL;

        temp = root;
    }
};

// Approach #2 - Recursive Approach - Similar to morris Tranversal
class Solution
{
    TreeNode *solve(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        TreeNode *left = solve(root->left);
        TreeNode *right = solve(root->right);
        if (left && right)
        {
            TreeNode *leftright = left;
            while (leftright->right)
            {
                leftright = leftright->right;
            }
            root->right = left;
            leftright->right = right;
        }
        else if (left && !right)
        {
            root->right = left;
        }
        root->left = NULL;
        return root;
    }

public:
    void flatten(TreeNode *root)
    {
        solve(root);
    }
};

// Approach #3 - Morris Transversal
class Solution
{
public:
    void flatten(TreeNode *root)
    {

        TreeNode *curr = root;
        TreeNode *prev;
        while (curr != NULL)
        {
            if (curr->left != NULL)
            {
                prev = curr->left;
                while (prev->right != NULL)
                {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        return;
    }
};

// Space Complexity - O(N) - Using an extra storage
class Solution
{
    void solve(TreeNode *root, vector<TreeNode *> &v)
    {
        if (root == NULL)
            return;
        v.push_back(root);
        solve(root->left, v);
        solve(root->right, v);
    }

public:
    void flatten(TreeNode *root)
    {
        vector<TreeNode *> v;
        solve(root, v);
        TreeNode *list = root;

        for (int i = 1; i < v.size(); i++)
        {
            list->right = v[i];
            list->left = NULL;
            list = list->right;
        }
        root = list;
    }
};