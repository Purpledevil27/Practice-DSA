// https://leetcode.com/problems/binary-tree-right-side-view/

/*Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,null,3]
Output: [1,3]

Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 100].
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

// Approach #1 - Better
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> store;
        rightSideViewHelp(root, store, 0);
        return store;
    }

    void rightSideViewHelp(TreeNode *root, vector<int> &store, int level)
    {

        if (root == NULL)
            return;

        if (level == store.size())
            store.push_back(root->val);

        rightSideViewHelp(root->right, store, level + 1);
        rightSideViewHelp(root->left, store, level + 1);
    }
};

// Approach #2 - Finding Height
class Solution
{

    int find_height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + max(find_height(root->left), find_height(root->right));
    }

public:
    void solve(TreeNode *root, int h, int dp[])
    {
        if (root == NULL)
            return;
        dp[h] = root->val;
        solve(root->left, h + 1, dp);
        solve(root->right, h + 1, dp);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        int height = find_height(root);
        int dp[height + 1];
        solve(root, 1, dp);
        for (int i = 1; i <= height; i++)
        {
            ans.push_back(dp[i]);
        }
        return ans;
    }
};
