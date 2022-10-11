// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

/*You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

Example 1:

Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

Example 2:

Input: root = [0]
Output: 0

Constraints:
The number of nodes in the tree is in the range [1, 1000].
Node.val is 0 or 1.
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
    int sumRootToLeaf(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int curr = 0;
        return sum(root, curr);
    }

    int sum(TreeNode *root, int curr)
    {
        if (root == NULL)
            return 0;

        curr = 2 * curr + root->val;

        if (root->left == NULL && root->right == NULL)
            return curr;

        return sum(root->left, curr) + sum(root->right, curr);
    }
};

// Approach #2
class Solution
{
    int sum = 0;
    void solve(TreeNode *root, string s)
    {
        if (root->left == NULL && root->right == NULL)
        {
            s += ('0' + root->val);
            // converting binary string to integer
            sum += stoi(s, 0, 2);
            return;
        }
        if (root->left)
        {

            solve(root->left, s + string(1, root->val + '0'));
        }
        if (root->right)
        {
            solve(root->right, s + string(1, root->val + '0'));
        }
    }

public:
    int sumRootToLeaf(TreeNode *root)
    {
        string s;
        solve(root, s);
        return sum;
    }
};