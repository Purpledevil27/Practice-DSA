// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

/*Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

Example 1:

Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

Example 2:

Input: root = [1,null,2,null,0,3]
Output: 3

Constraints:
The number of nodes in the tree is in the range [2, 5000].
0 <= Node.val <= 10^5
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
    int ans = INT_MIN;
    pair<int, int> solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return {INT_MAX, INT_MIN};
        }
        pair<int, int> l = solve(root->left);
        pair<int, int> r = solve(root->right);

        int mi = min(l.first, r.first);
        int mx = max(l.second, r.second);

        if (mi != INT_MAX)
        {
            ans = max(ans, abs(mi - root->val));
        }
        if (mx != INT_MIN)
        {
            ans = max(ans, abs(mx - root->val));
        }
        return {min(mi, root->val), max(mx, root->val)};
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        solve(root);
        return ans;
    }
};

// Approach #2
class Solution
{
public:
    int maxAncestorDiff(TreeNode *root, int curMax = INT_MIN, int curMin = INT_MAX)
    {
        if (!root)
            return curMax - curMin;
        curMin = min(curMin, root->val);
        curMax = max(curMax, root->val);
        return max(maxAncestorDiff(root->left, curMin, curMax), maxAncestorDiff(root->right, curMin, curMax));
    }
};
