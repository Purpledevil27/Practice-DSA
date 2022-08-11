// https://leetcode.com/problems/validate-binary-search-tree/

/*Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:

Input: root = [2,1,3]
Output: true

Example 2:

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1
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
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;

        vector<int> v;

        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *top = s.top();
            if (top->left)
            {
                s.push(top->left);
                top->left = NULL;
            }
            else
            {
                v.emplace_back(top->val);
                s.pop();
                if (top->right)
                {
                    s.push(top->right);
                }
            }
        }
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] <= v[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};