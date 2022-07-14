// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

/*Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.

Example 1:

Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]

Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]

Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
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

// Approach #1 - O(N) - one pass
class Solution
{
public:
    int preIndex = 0, posIndex = 0;
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        TreeNode *root = new TreeNode(pre[preIndex++]);
        if (root->val != post[posIndex])
            root->left = constructFromPrePost(pre, post);
        if (root->val != post[posIndex])
            root->right = constructFromPrePost(pre, post);
        posIndex++;
        return root;
    }
};

// Approach #2
class Solution
{
    TreeNode *help(vector<int> &preorder, vector<int> &postorder, int preorderStart, int preorderEnd, int postorderStart, int postorderEnd, unordered_map<int, int> &m)
    {
        if (postorderStart > postorderEnd)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preorderStart]);
        if (preorderStart + 1 <= preorderEnd)
        {
            int leftTreeSize = m[preorder[preorderStart + 1]] - postorderStart;

            int rightpostorderStart = postorderStart + leftTreeSize + 1;
            int rightpostorderEnd = postorderEnd - 1;
            int rightPreorderStart = preorderStart + 1 + leftTreeSize + 1;
            int rightPreorderEnd = preorderEnd;
            int leftpostorderStart = postorderStart;
            int leftpostorderEnd = postorderStart + leftTreeSize;
            int leftPreorderStart = preorderStart + 1;
            int leftPreorderEnd = preorderStart + 1 + leftTreeSize;

            root->left = help(preorder, postorder, leftPreorderStart, leftPreorderEnd, leftpostorderStart, leftpostorderEnd, m);
            root->right = help(preorder, postorder, rightPreorderStart, rightPreorderEnd, rightpostorderStart, rightpostorderEnd, m);
        }
        return root;
    }

public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < postorder.size(); i++)
        {
            m[postorder[i]] = i;
        }
        int preorderStart = 0, preorderEnd = preorder.size() - 1, postorderStart = 0, postorderEnd = postorder.size() - 1;
        TreeNode *root = help(preorder, postorder, preorderStart, preorderEnd, postorderStart, postorderEnd, m);
        return root;
    }
};