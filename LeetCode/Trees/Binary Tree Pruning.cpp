// https://leetcode.com/problems/binary-tree-pruning/

/*Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.

Example 1:

Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation:
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

Example 2:

Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

Example 3:

Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]

Constraints:
The number of nodes in the tree is in the range [1, 200].
Node.val is either 0 or 1.
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

// Approach #1
class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (!root)
            return NULL;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (!root->left && !root->right && root->val == 0)
            return NULL;

        return root;
    }
};

// Approach #2
class Solution
{
    bool solve(TreeNode *root)
    {
        bool pruneL = true, pruneR = true;
        if (root->left)
        {
            pruneL = solve(root->left);
            if (pruneL)
                root->left = NULL;
        }
        if (root->right)
        {
            pruneR = solve(root->right);
            if (pruneR)
                root->right = NULL;
        }
        if (root->val == 0 && pruneR && pruneL)
            return true;

        return false;
    }

public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (!root)
            return root;
        bool prune = solve(root);
        if (prune)
            return NULL;
        return root;
    }
};