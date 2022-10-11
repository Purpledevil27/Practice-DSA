// https://leetcode.com/problems/deepest-leaves-sum/

// similar to https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

/*Given the root of a binary tree, return the sum of values of its deepest leaves.

Example 1:

Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
1 <= Node.val <= 100
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

// BFS
class Solution
{
public:
    int deepestLeavesSum(TreeNode *root, int d = 0)
    {
        if (root == NULL)
        {
            return 0;
        }
        int sum = 0;
        queue<TreeNode *> q;
        q.push(root);
        q.push(new TreeNode(-1));
        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            if (t->val == -1)
            {
                if (!q.empty())
                {
                    sum = 0;
                    q.push(new TreeNode(-1));
                    continue;
                }
                else
                {
                    break;
                }
            }
            sum += t->val;
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        return sum;
    }
};

// DFS
class Solution
{
public:
    int deepest = 0;
    int sum = 0;

    void dfs(TreeNode *root, int dep)
    {
        if (root->left)
        {
            dfs(root->left, dep + 1);
        }
        if (root->right)
        {
            dfs(root->right, dep + 1);
        }
        if (!root->left && !root->right)
        {
            if (dep == deepest)
            {
                sum += root->val;
            }
            else if (dep > deepest)
            {
                deepest = dep;
                sum = root->val;
            }
        }
    }

    int deepestLeavesSum(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        dfs(root, 0);
        return sum;
    }
};