// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

/*Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

Example 1:

Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

Example 2:

Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.

Constraints:
The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].
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
    int solve(TreeNode *root, int maxVal)
    {
        if (root == NULL)
            return 0;

        maxVal = max(root->val, maxVal);
        if (root->val >= maxVal)
            return 1 + solve(root->left, maxVal) + solve(root->right, maxVal);

        return solve(root->left, maxVal) + solve(root->right, maxVal);
    }

    int goodNodes(TreeNode *root)
    {
        return solve(root, INT_MIN);
    }
};

// Using Stack
class Solution
{
    int count = 0;
    bool find(TreeNode *root, stack<int> &s)
    {
        if (root == NULL)
        {
            return false;
        }
        bool c = false;
        if (!s.empty() && s.top() <= root->val)
        {
            count++;
            s.push(root->val);
            c = true;
        }
        bool ans = find(root->left, s);
        if (ans)
            s.pop();
        ans = find(root->right, s);
        if (ans)
            s.pop();
        return c;
    }

public:
    int goodNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        stack<int> s;
        find(root, s);
        return count;
    }
};