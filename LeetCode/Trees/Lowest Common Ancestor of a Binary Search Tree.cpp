// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/*Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2

Constraints:

The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the BST.

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

// Iterative
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *currNode = root;
        while (true)
        {
            if (p->val < currNode->val && q->val < currNode->val)
            {
                currNode = currNode->left;
            }
            else if (p->val > currNode->val && q->val > currNode->val)
            {
                currNode = currNode->right;
            }
            else
            {
                return currNode;
            }
        }
        return nullptr;
    }
};

// Recursive - Applicable to Binary Tree & BST
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root == p || root == q)
        {
            return root;
        }
        TreeNode *a = lowestCommonAncestor(root->left, p, q);
        TreeNode *b = lowestCommonAncestor(root->right, p, q);
        if (a == NULL && b == NULL)
            return NULL;
        else if ((!a and b) or (a and !b))
        {
            return a == NULL ? b : a;
        }
        else
        {
            return root;
        }
    }
};

// Recursive - BST only
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
        {
            return NULL;
        }
        if (p->val < root->val && q->val < root->val)
        {
            root = lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val)
        {
            root = lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};