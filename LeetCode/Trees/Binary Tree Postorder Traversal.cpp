// https://leetcode.com/problems/binary-tree-postorder-traversal/

/*Given the root of a binary tree, return the postorder traversal of its nodes' values.



Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]


Constraints:
The number of the nodes in the tree is in the range [0, 100].
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

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *top = s.top();
            s.pop();

            if (top->left)
            {
                s.push(top->left);
            }
            if (top->right)
            {
                s.push(top->right);
            }
            ans.push_back(top->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<int> ans;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *curr = s.top();
            if (curr->left)
            {
                s.push(curr->left);
                curr->left = NULL;
            }
            else
            {
                if (curr->right)
                {
                    s.push(curr->right);
                    curr->right = NULL;
                }
                else
                {
                    ans.push_back(curr->val);
                    s.pop();
                }
            }
        }
        return ans;
    }
};