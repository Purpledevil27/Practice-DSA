// https://leetcode.com/problems/leaf-similar-trees/

/*Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Example 1:

Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true

Example 2:

Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false

Constraints:
The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].
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
    void solve1(TreeNode *root, vector<int> &v1)
    {
        if (!root->left && !root->right)
        {
            v1.push_back(root->val);
            return;
        }
        if (root->left)
            solve1(root->left, v1);
        if (root->right)
            solve1(root->right, v1);
    }
    void solve2(TreeNode *root, vector<int> &v2)
    {
        if (!root->left && !root->right)
        {
            v2.push_back(root->val);
            return;
        }
        if (root->left)
            solve2(root->left, v2);
        if (root->right)
            solve2(root->right, v2);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1, v2;
        solve1(root1, v1);
        solve2(root2, v2);
        return v1 == v2;
    }
};