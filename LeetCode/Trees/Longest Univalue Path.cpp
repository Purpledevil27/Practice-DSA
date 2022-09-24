// https://leetcode.com/problems/longest-univalue-path/

/*Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them.

Example 1:

Input: root = [5,4,5,1,1,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 5).

Example 2:

Input: root = [1,4,5,4,4,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 4).

Constraints:
The number of nodes in the tree is in the range [0, 10^4].
-1000 <= Node.val <= 1000
The depth of the tree will not exceed 1000.
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
    int dfs(TreeNode *node, int &lup)
    {
        int l = 0, r = 0;
        if (node->left)
        {
            l = dfs(node->left, lup);
        }
        if (node->right)
        {
            r = dfs(node->right, lup);
        }
        int retl = 0, retr = 0;
        if (node->left && node->left->val == node->val)
        {
            retl = l + 1;
        }
        if (node->right && node->right->val == node->val)
        {
            retr = r + 1;
        }

        lup = max(lup, retl + retr);
        // cout << lup << " " <<node->val << endl;
        return max(retl, retr);
    }

public:
    int longestUnivaluePath(TreeNode *root)
    {
        int ans = 0;
        if (root)
            dfs(root, ans);
        return ans;
    }
};