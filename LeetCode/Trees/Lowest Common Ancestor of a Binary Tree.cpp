// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/*Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1

Constraints:
The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the tree.
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

class Solution
{
public:
    // Iterative
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *cur = root, *last = nullptr;
        vector<TreeNode *> pathp, pathq, temp;

        while (pathp.empty() || pathq.empty())
        {

            // standard post-order iterative tree traversal
            if (cur)
            {
                temp.push_back(cur);
                if (temp.back() == p)
                    pathp = temp; // check and set path for p
                if (temp.back() == q)
                    pathq = temp; // check and set path for q
                cur = cur->left;
            }
            else
            {
                if (temp.back()->right && temp.back()->right != last)
                {
                    cur = temp.back()->right;
                }
                else
                {
                    last = temp.back();
                    temp.pop_back();
                }
            }
        }

        // compare paths and get lowest common ancestor
        int n = min(pathp.size(), pathq.size());
        for (int i = 1; i < n; i++)
        {
            if (pathp[i] != pathq[i])
                return pathp[i - 1];
        }
        return pathp[n - 1];
    }
};

class Solution
{
public:
    // Recusive
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