// https://leetcode.com/problems/count-complete-tree-nodes/

/*Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Example 1:

Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:

Input: root = []
Output: 0

Example 3:

Input: root = [1]
Output: 1

Constraints:
The number of nodes in the tree is in the range [0, 5 * 10^4].
0 <= Node.val <= 5 * 10^4
The tree is guaranteed to be complete.
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
    int findheightleft(TreeNode *root)
    {
        int h = 0;
        while (root)
        {
            root = root->left;
            h++;
        }
        return h;
    }
    int findheightright(TreeNode *root)
    {
        int h = 0;
        while (root)
        {
            root = root->right;
            h++;
        }
        return h;
    }

public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lh = findheightleft(root);
        int rh = findheightright(root);
        if (lh == rh)
        {
            return (1 << lh) - 1;
        }
        else
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};