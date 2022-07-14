// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]


Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
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
    unordered_map<int, int> ValToIndex;
    int preIndex = 0;
    TreeNode *build(int left, int right, vector<int> &preorder)
    {
        if (left > right)
            return NULL;
        TreeNode *root = new TreeNode(preorder[preIndex++]);
        int mid = ValToIndex[root->val];
        root->left = build(left, mid - 1, preorder);
        root->right = build(mid + 1, right, preorder);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            ValToIndex[inorder[i]] = i;
        return build(0, n - 1, preorder);
    }
};

// Approach #2
class Solution
{
    TreeNode *help(vector<int> &preorder, vector<int> &inorder, int preorderStart, int preorderEnd, int inorderStart, int inorderEnd)
    {
        if (inorderStart > inorderEnd)
        {
            return NULL;
        }
        int rootData = preorder[preorderStart];
        int rootIndex = -1;
        for (int i = inorderStart; i <= inorderEnd; i++)
        {
            if (inorder[i] == rootData)
            {
                rootIndex = i;
                break;
            }
        }

        int leftInorderStart = inorderStart;
        int leftInorderEnd = rootIndex - 1;
        int leftPreorderStart = preorderStart + 1;
        int leftPreorderEnd = (leftInorderEnd - leftInorderStart) + leftPreorderStart;
        int rightInorderStart = rootIndex + 1;
        int rightInorderEnd = inorderEnd;
        int rightPreorderStart = leftPreorderEnd + 1;
        int rightPreorderEnd = preorderEnd;

        TreeNode *root = new TreeNode(rootData);
        root->left = help(preorder, inorder, leftPreorderStart, leftPreorderEnd, leftInorderStart, leftInorderEnd);
        root->right = help(preorder, inorder, rightPreorderStart, rightPreorderEnd, rightInorderStart, rightInorderEnd);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int preorderStart = 0, preorderEnd = preorder.size() - 1, inorderStart = 0, inorderEnd = inorder.size() - 1;
        TreeNode *root = help(preorder, inorder, preorderStart, preorderEnd, inorderStart, inorderEnd);
        return root;
    }
};