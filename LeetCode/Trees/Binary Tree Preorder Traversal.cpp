// https://leetcode.com/problems/binary-tree-preorder-traversal/

/*Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively?
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

// Iterative approach
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *t = s.top();
            s.pop();
            ans.push_back(t->val);
            if (t->right)
            {
                s.push(t->right);
            }
            if (t->left)
            {
                s.push(t->left);
            }
        }
        return ans;
    }
};

// Recursive approach
class Solution
{
public:
    void find(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        ans.push_back(root->val);
        find(root->left, ans);
        find(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        find(root, ans);
        return ans;
    }
};
